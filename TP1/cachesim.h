#include <sys/types.h>
#include <stdint.h>
#define ESIZE 38 // Número de carácteres por linea del archivo .xex

typedef struct operacion op_t;
typedef struct linea linea_t;

/*
 * Verifica que n sea potencia de 2. Es decir, esto ocurre si n = 2^p, con p natural
 * (es decir, ceil(p) = floor(p)).
 * Precondiciones: recibe un entero no signado.
 * Postcondiciones: devuelve 1 si se cumple la condición, 0 de lo contrario.
 */
int is_pow2(int n);

/*
 * Esta función abre y lee el archivo de traza, con los datos que entraron por argumento.
 * Simula la lectura y escritura de cachés y puede ejecutarse con un modo verboso que muestra
 * el progreso de las ejecuciones. Finalmente imprime una serie de estadísticas relacionadas
 * al proceso correspondiente.
 * Precondiciones: Recibe file descriptor válido y luego todos números no negativos.
 * Postcondiciones: Al finalizar devuelve 0 en caso de que ho hayan salido errores
 *				   de lo contrario saldrá con estado diferente de 0
 */
int work_file(int fd, int n, int m, double tam, double cols, double sets);

/*
 * Crea, con memoria dinámica, el struct que guarda todos los elementos importantes de cada
 * línea del archivo de trazas.
 * Precondiciones: Recibe el buffer con datos diferente de NULL, y t y s, número de bits de tag
 *                 y set correspondientemente, no negativos.
 * Postcondiciones: Devuelve un puntero al struct correspondiente, o NULL si hubo un error.
 */
op_t* crear_operacion(char buf[ESIZE], int t, int s);

/*
 * Recibe struct operacion y libera toda la memoria que este pidió.
 * Precondiciones: Debe ser diferente de NULL.
 * Postcondiciones: Libera toda la memoria asociada al mismo.
 */
void destruir_operacion(op_t* operacion);

/*
 * Guarda el tag y el set en el struct operacion, dados los datos introducidos.
 * Precondiciones: Los punteros deben ser diferentes de NULL, con t y s números no negativos.
 * Postcondiciones: Dejan el tag y set en el op_t dado. Si ocurre algún error en medio de la
 *                  ejecución, se dejara el *validbit en 1.
 */
void get_tag_n_set(op_t* op, int t, int s, char buf[ESIZE],int *opnotvalid);

/*
 * Crea la estructura que emula el comportamiento de una caché. Trabaja con memoria dinámica
 * y la administración de la misma depende del usuario.
 * Precondiciones: Recibe dos números positivos.
 * Postcondiciones: Devuelve la estructura creada e inicializada con callocs.
 */
linea_t** simular_cache(int cols,int sets);

/*
 * Elimina correspondientemente la estructura que se le pasa, liberando también la memoria
 * de los punteros correspondiente a la misma.
 * Precondiciones: Se le pasa un puntero de punteros, todos diferentes de NULL, y luego números positivos.
 * Postcondiciones: Elimina toda la memoria allocada por el creador de la estructura. 
 */
void destruir_cache(linea_t** cache,int cols, int sets);

/*
 * DOCUMENTAR
 * Precondiciones:  ...
 * Postcondiciones: ...
 */
void ubicar_en_cache(linea_t** cache, op_t* op);

// ELIMINAR ANTES DE LA ENTREGA FINAL, SOLO PARA TESTING.
void show_cache(linea_t** cache,int cols,int sets);
