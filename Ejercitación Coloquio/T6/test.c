#include <stdio.h>
#include <string.h>

struct a{
	int x;
	void* p;
};

struct b{
	int v[3];
	long x;
	void* p;
};

struct c{
	short v[9];
	int* x;
	char c;
};

union d{
	char m;
	struct{
		int n;
		char x;
	}s;
};

void partA(){
	printf("The sizes of a is: %ld\n",sizeof(struct a));
	printf("The sizes of b is: %ld\n",sizeof(struct b));
	printf("The sizes of c is: %ld\n",sizeof(struct c));
	printf("The sizes of d is: %ld\n",sizeof(union  d));
}

int  get_a_x(struct a *s){return s->x;}
long get_b_x(struct b *s){return s->x;}
int* get_c_x(struct c *s){return s->x;}
char get_d_x(union  d *p){return p->s.x;}

void partCD(){

	long v[] = {20,30,40,50,60};
	char* s = "hola";
	char p[] = "mundo";

	printf("Tamaños: \n sizeof(v): %ld\n sizeof(s): %ld\n sizeof(*v): %ld\n sizeof(p): %ld\n sizeof(&v[0]): %ld\n", sizeof(v), sizeof(s), sizeof(*v), sizeof(p), sizeof(&v[0]));

	printf("Valores extra: \n *(s+3): %c \n &v[3]-&v[1]: %ld \n &p[3]-&p[1]: %ld \n strlen(&p[1]): %ld \n strlen(&p[5]): %ld \n p[4]-p[2]: %x \n",*(s+3),&v[3]-&v[1],&p[3]-&p[1],strlen(&p[1]),strlen(&p[5]),p[4]-p[2]);
	
	// sizeof(*********************...***array_n_dimensional[n]) = sizeof(void*) * 8 -> en 64 bits 8 * n
	// sizeof(&cualquiercosa) = sizeof(*cualquierpuntero)
	// &ptr[a] - &ptr[b] = a - b.
	// En p[4] - p[2] está restando los valores de la tabla ascii -> la 'n' está a 2 posiciones de la 'o'.
}

void partD(){}

int main(void){
	
	partA();
	partCD();
	return 0;
}
