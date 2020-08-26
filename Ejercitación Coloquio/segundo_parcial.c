#include <stdio.h>
#include <stddef.h>

#define MSJSIZES "sizeof(%s): %ld | padding externo: %ld | offsets;"

//void assert(char* msj, bool condition);
//void equals(char* msj, const void* x, const void* y, bool(*test)(const void* a, const void* b));

//---------------------------------------------------------------

struct a{int n;};
struct mini{char c; short s;};
typedef struct p1{short i; int c; int *j; short *d;}ej;

void ejs_libro(){
	printf("Hello world! the size of a is: %ld\n",sizeof(struct a));
	printf("And the size of P1 is: %ld\n",sizeof(struct p1));
	printf("Offsets: \ni: %ld, c: %ld, j: %ld, d: %ld\n",offsetof(ej,i),offsetof(ej,c),offsetof(ej,j),offsetof(ej,d));
	printf("Struct mini total size: %ld & offsets: c: %ld, s: %ld\n",sizeof(struct mini),offsetof(struct mini,c),offsetof(struct mini,s));
}

// 4A -----------------------------------------------------------

typedef struct primero {long l; char c; int  i;} a;
typedef struct segundo {int  i; long l; char c; int j;} b;
typedef struct tercero {int  i; long l; char c;} c;

// Al ejecutarse esta función imprimirá las respuestas de los números pedidos del ejercicio.
void ej_4a(){

	printf(MSJSIZES" l: %ld, c: %ld, i: %ld\n","a",sizeof(a),sizeof(a)-sizeof(int)-offsetof(a,i),offsetof(a,l),offsetof(a,c),offsetof(a,i));
	printf(MSJSIZES" i: %ld, l: %ld, c: %ld, j: %ld\n","b",sizeof(b),sizeof(b)-sizeof(int)-offsetof(b,j),offsetof(b,i),offsetof(b,l),offsetof(b,c),offsetof(b,j));
	printf(MSJSIZES" i: %ld, l: %ld, c: %ld\n","c",sizeof(c),sizeof(c)-sizeof(char)-offsetof(c,c),offsetof(c,i),offsetof(c,l),offsetof(c,c));

}

// 4C -----------------------------------------------------------

      /* %RDI v | %RSI v */
short f(short a, short b){
	short result = 0;
	while (a > b){
		result = result + a * b;
		a = a - 1;
	}
	return result;
}

/*
1  f:
2     movl $0, %eax           -> Valor a devolver
3     jmp .L2
4 .L3:
5     leaq (,%rsi,%rdi), %rdx -> t = a * b;
6     addq %rdx, %rax         -> result += t;
7     subq $1, %rdi
8 .L2:
9     cmpq %rsi, %rdi         -> (a - b > 0)
10    jg .L3
11    ret 
*/

// 4C -----------------------------------------------------------

    /* %RDI v | %RSI v */
long g(long a,  long b){
	long result = b;
	while (b > 0){
		result = result * a;
		b = b - a;
	}
	return result;
}

/*
15 g:
16    testq %rsi, %rsi ----------------v       No queremos que se active el ZF ni el SF 
17    jle .L8          -> Salta si (b <= 0) <= como producto de la comparación de testq.
18    movq %rsi, %rax
19 .L7:
20    imulq %rdi, %rax -> result *= a;
21    subq %rdi, %rsi
22    testq %rsi, %rsi ----------------v
23    jg .L7           -> No salta si (b <= 0)
24    ret
25 .L8:
26    movq %rsi, %rax
27    ret
*/
