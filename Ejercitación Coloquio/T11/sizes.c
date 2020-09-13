#include <stdio.h>
#include <string.h>

struct a{
	int v[4];
	void* p;
};

struct b{
	int v[4];
	char c;
	void* p;
};

struct c{
	short v[9];
	void* p;
};

union u{
	int i;
	char *s;
};

union v{
	char* m;
	struct{
		int x;
		void* p;
	}s;
};

void partA(){
	printf("The sizes of a is: %ld\n",sizeof(struct a));
	printf("The sizes of b is: %ld\n",sizeof(struct b));
	printf("The sizes of c is: %ld\n",sizeof(struct c));
	printf("The sizes of u is: %ld\n",sizeof(union  u));
	printf("The sizes of v is: %ld\n",sizeof(union  v));
}

void partCDE(){

	int v[] = {100,200,300,400};
	char* s    = "hola";
	char ars[] = "hola";
	char arr[] = {'h','o','l','a','\0'};

	printf("\nTamaños: \n sizeof(v): %ld\n sizeof(*v): %ld\n sizeof(s): %ld\n sizeof(*s): %ld\n sizeof(arr): %ld\n sizeof(arr[1]): %ld\n sizeof(ars): %ld\n sizeof(&ars[2]): %ld\n", sizeof(v), sizeof(*v), sizeof(s), sizeof(*s), sizeof(arr), sizeof(arr[1]),sizeof(ars), sizeof(&ars[2]));

	printf("\nValores extra: \n &s[3] - s: %ld \n &v[3]-&v[1]: %ld \n (v + 2) - v: %ld\n  strlen(s + 2): %ld \n strlen(&arr[1]): %ld \n strlen(&ars[4]): %ld \n",&s[3]-s,&v[3]-&v[1],(v+2)-v,strlen(s+2),strlen(&arr[1]),strlen(&ars[4]));
	
	// sizeof(*********************...***array_n_dimensional[n]) = sizeof(void*) * 8 -> en 64 bits 8 * n
	// sizeof(&cualquiercosa) = sizeof(*cualquierpuntero)
	// &ptr[a] - &ptr[b] = a - b.
	// En p[4] - p[2] está restando los valores de la tabla ascii -> la 'n' está a 2 posiciones de la 'o'.

	printf("\nPUNTAJE EXTRA: \n strlen((char*)(v+1)): %ld\n strlen((char*)(v+2)): %ld\n strlen(((char*) v)+ 6): %ld\n strlen(((char*) v)+ 9): %ld\n\n",strlen((char*)(v+1)),strlen((char*)(v+2)),strlen(((char*)v)+6),strlen(((char*)v)+9));

	// Conviene dibujar a v[] con sus datos (little endian) y tener siempre en cuenta que al castear de int v[]  a char* v, los bytes ceros de la representación númerica se tranforman en '\0' => el char* va a quedar con muchos ceros => contar manualmente los bytes hasta el primer '\0'
}

int main(){
	partA(); partCDE();
	return 0;
}
