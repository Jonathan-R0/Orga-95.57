funcion:

	/* f --> %rdi (probablemente sean filas)
	   c --> %rsi (probablemente sean columnas)
	  *v -> %rdx */

	movl $0, %r8d /* SOSPECHO QUE i -> r8 */
	movl $-7, (%rdx) /* *v = -7 */
	jmp .L2
.L5:
	leaq (%r8,%r8,2), %rax
	salq $5, %rax
	movl $-1, mglobal(%rax)
	leaq 1(%r8), %r11
	movq %r11, %r9
	jmp .L3
.L4:
	leaq (%r8,%r8), %rax
	leaq (%rax,%r8), %rcx
	salq $3, %rcx
	subq %r8, %rcx
	addq %r9, %rcx
	addq %r8, %rax
	salq $5, %rax
	movl mglobal(%rax), %r10d
	addl mglobal(,%rcx,4), %r10d
	movl %r10d, mglobal(%rax)
	addq $1, %r9
.L3:
	cmpq %rsi, %r9
	jb .L4
	leaq (%r8,%r8,2), %rax
	salq $5, %rax
	movl mglobal(%rax), %eax
	addl %eax, (%rdx)
	movq %r11, %r8
.L2:
	cmpq %rdi, %r8 # i < f -> L5
	jb .L5
	movl (%rdx), %edx
	movslq %edx, %rax
	cmpl $1289, %edx
	movq $-1, %rdx
	cmovb %rdx, %rax
	ret
