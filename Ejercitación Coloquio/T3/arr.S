.globl arr_ordenado

arr_ordenado:
	pushq %rbx
	movq %rdi,%rbx
.loop:
	movq (%rbx),%rdi
	addq $8,%rbx
.start:
	movq $1,%rax
	movq (%rbx),%rsi
	testq %rsi,%rsi
	jz .end
	callq strcmp
	cmpq $0,%rax
	jle .loop
	xorq %rax,%rax
.end:
	popq %rbx
	ret
