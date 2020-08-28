#include <stdio.h>
#include <string.h>
#include <stddef.h>

struct a{
	int x;
	void* p;
};

struct b{
	char s[3];
	int i;
	short v[5];
	void *p;
	unsigned u;
};

union u{
	char* m;
	struct{
		int n;
		char x;
	}s;
};

void partA(){
	printf("The sizes of a is: %ld\n",sizeof(struct a));
	printf("The sizes of b is: %ld\n",sizeof(struct b));
	printf("The sizes of u is: %ld\n",sizeof(union  u));
	printf("checc: %ld\n",offsetof(struct b,u));
}

int  get_a_x(struct a *s){return s->x;}
long get_bs_x(struct b *s){return s->s[3];}
long get_bv_x(struct b *s){return s->v[5];}
char get_d_x(union  u *s){return s->s.x;}

int main(void){
	
	partA();
	return 0;
}
