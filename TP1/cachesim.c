#define _POSIX_C_SOURCE 200809L
#include <errno.h>
#include <fcntl.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>
#include "cachesim.h"

#define S sets
#define E cols
#define C tam

#define ERROR1 "Error, número de argumentos inválido.\n"
#define ERROR2 "Error, no se cumple que 0 <= n <= m.\n"
#define ERROR3 "Error, el tamaño del caché, cantidad de sets o número de bloques por set no es potencia de dos.\n"
#define ERROR4 "Error, el archivo de trazas específicado no existe.\n"
#define ERROR5 "Error al guardar datos del archivo de trazas.\n"
#define ESIZE 38 // Número de carácteres por linea del archivo .xex
#define DIRSIZE 32 // Máximo número de bits por dirección de memoria.

#define MSJ1 "%d-way, %d sets, size = %dKB\n",(int)E,(int)S,(int)(C/1024)
#define MSJ2 "loads %d stores %d total %d\n",reads,writes,reads+writes
#define MSJ3 "rmiss %d wmiss %d total %d\n",rmiss,wmiss,rmiss+wmiss
#define MSJ4 "dirty rmiss %d dirty wmiss %d\n",drmiss,dwmiss
#define MSJ5 "bytes read %d bytes written %d\n",bread,bwritten
#define MSJ6 "read time %d write time %d\n",readtime,writetime
#define MSJ7 "miss rate %f\n",missrate

//-------------------------------------------------------------------------------

 // POTENCIAL ERROR: Que manden una cadena random en vez de un -v
 // y que entre al modo verboso cuando no debería

 // POTENCIAL ERROR 2: Yo defino ESIZE como 38 bytes, pero eso solo se
 // cumple si el instruction_line tiene 30 bits como se ve en el .xex

 // Cambiar en algún momento el tamaño de los calloc para no pedir bytes al pedo.

 // Actualmente estoy allocando demasiada memoria. Lo que debería hacer, es 
 // una estructura que vaya creciendo de a poco, a medida que voy accediendo a 
 // direcciones de la cache. No debería tener un elemento en la matriz setteado
 // en cero para jamás usarlo (se pueden hacer búsquedas en O(n)).

//-------------------------------------------------------------------------------

struct operacion{
	char* mode;
	uint32_t* tag;
	uint32_t* set;
	char* amount;
};

struct linea{
	uint32_t tag;
	uint32_t set;
};

linea_t** simular_cache(int cols,int sets){
	linea_t** cache = malloc(sizeof(linea_t*)*S);
	if (cache == NULL) return NULL;
	for (int i = 0;i < S;i++){
		cache[i] = calloc(E,sizeof(linea_t));
		if (cache[i] == NULL){
			destruir_cache(cache,E,S);
			return NULL; 
		}
	}
	return cache;
}

void destruir_cache(linea_t** cache,int cols, int sets){
	for (int i = 0;i < S;i++) free(cache[i]);
	free(cache);
}

void get_tag_n_set(op_t* op, int t, int s, char buf[ESIZE],int *opnotvalid){

	char* dir;
	if ((dir = calloc(12,sizeof(char))) == NULL){
		*opnotvalid = 1;
		return;
	}
	dir = strncpy(dir,buf+13,11);

	//printf("Dirección: %s, ",dir);

	sscanf(dir,"%x",op->tag);
	sscanf(dir,"%x",op->set);
	*op->tag = *(op->tag) >> (DIRSIZE - t);         // t = Bits del tag.
	*op->set = (*(op->set) << t) >> (DIRSIZE - s);  // s = Bits del set.
	free(dir);
}


op_t* crear_operacion(char buf[ESIZE], int t, int s){
	op_t* op = malloc(sizeof(op_t));
	if (op == NULL){
		return NULL;
	}
	op->tag    = calloc(1,sizeof(uint64_t));
	op->set    = calloc(1,sizeof(uint64_t));
	op->mode   = calloc(2,sizeof(char));
	op->amount = calloc(2,sizeof(char));
	if (op->mode == NULL || op->amount == NULL ||
	    op->tag  == NULL || op->set    == NULL) {
		destruir_operacion(op);
		return NULL;
	}

	int opnotvalid = 0;

	op->mode   = strncpy(op->mode,buf+11,1);
	op->amount = strncpy(op->amount,buf+25,1);
	get_tag_n_set(op,t,s,buf,&opnotvalid);
	if (opnotvalid){ // Será 1 si no se pudo reservar la memoria.
		destruir_operacion(op);
		return NULL;
	}
	return op;
}

void destruir_operacion(op_t* operacion){
	free(operacion->amount);
	free(operacion->mode);
	free(operacion->set);
	free(operacion->tag);
	free(operacion);
}

void show_cache(linea_t** cache,int cols,int sets){
	for (int i = 0;i < sets;i++){
		for (int j = 0;j < cols;j++){
			printf("%x-%x ",(cache[i][j]).tag,(cache[i][j]).set);
		}
		printf("\n");
	} 
}

void ubicar_en_cache(linea_t** cache, op_t* op){
	int set = (int)(*(op->set));
	(cache[set][0]).set = *(op->set); // CAMBIAR EL 0 PARA QUE HAGA UNA BÚSQUEDA LINEAL
	(cache[set][0]).tag = *(op->tag); // Y ENCUENTRE EL TAG CORRESPONDIENTE
}


int work_file(int fd, int n, int m, double tam, double cols, double sets){

	char buf[ESIZE];
	int lines_read = 0;
	int s = log2(S);
	int t = DIRSIZE - (s + log2((C/(E*S))));
	linea_t** cache = simular_cache((int)E,(int)S);
	if (cache == NULL) return -1;

	int reads,writes,rmiss,wmiss,drmiss,dwmiss,bread,bwritten,readtime,writetime;
	reads = writes = rmiss = wmiss = drmiss = dwmiss = bread = bwritten = readtime = writetime = 0;
	float missrate = 0;

	// Siendo cada línea del .xex:
	// <instruction_line>: <mode> <target_line> <amount> <data_line>

	while (lines_read != 1000){
		if (read(fd,buf,ESIZE) == -1){
			perror("Error: ");
			return -1;
		}
		buf[ESIZE - 1] = '\0'; // Evitar problemas con el read.

		op_t* operacion;
		if ((operacion = crear_operacion(buf,(int)t,(int)s)) == NULL){
			fprintf(stderr,ERROR5);
			return -1;
		}

		(*(operacion->mode) == 'R')? writes++ : reads++; 

		// El %x te deja imprimir uint32_t.
		//printf("modo: %s, tag: %x, set: %x, monto: %s\n",operacion->mode,*(operacion->tag),*(operacion->set),operacion->amount);
		ubicar_en_cache(cache,operacion);
	
		if (n <= lines_read && m >= lines_read){
			// IMPLEMENTAR EL CÓDIGO PARA EL MODO VERBOSO.
		}
		destruir_operacion(operacion);
		lines_read++;
	}
	printf(MSJ1);
	printf(MSJ2);
	printf(MSJ3);
	printf(MSJ4);
	printf(MSJ5);
	printf(MSJ6);
	printf(MSJ7);
	
	show_cache(cache,E,S);
	destruir_cache(cache,E,S);
	return 0;
}

int is_pow2(int n){
	return (ceil(log2((double) n)) == floor(log2((double) n)));
}

int main(int argc, char *argv[]){

	int n = -1; int m = -1;

	if (argc == 8) { // Modo verboso.
		n = strtol(argv[6],NULL,10); // Uso strtol pues funciona como atoi: atoi(A) = strtol(A,NULL,10)
		m = strtol(argv[7],NULL,10); // y es mucho más segura; atoi no detecta errores.
		if (0 > n || 0 > m || n > m){
			fprintf(stderr, ERROR2);
			return -1;

		}
	} else if (argc != 5) {
		fprintf(stderr, ERROR1);
		return -1;
	}

	int tam = strtol(argv[2],NULL,10);
	int cols = strtol(argv[3],NULL,10); // Supongo que son la cantidad de bloques por set.
	int sets = strtol(argv[4],NULL,10);
	int fd;

	if (!(is_pow2(tam)  &&
	      is_pow2(cols) &&
	      is_pow2(sets))){
		fprintf(stderr, ERROR3);
		return -1;
	}

	if ((fd = open(argv[1], O_RDONLY)) == -1) {
		fprintf(stderr, ERROR4);
		return -1;
	}

	int resultado = work_file(fd,n,m,(double)tam,(double)cols,(double)sets);
	close(fd);

	return resultado; // Si todo sale bien, read_file debería devolver 0.
}
