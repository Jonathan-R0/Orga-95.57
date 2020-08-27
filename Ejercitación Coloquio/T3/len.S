.globl my_strlen

my_strlen:
	xorq %rax,%rax
	cmpb $0,(%rdi)
	jne .L1
	ret
.L2:
	incq %rax
	incq %rdi
.L1:
	cmpb $0,(%rdi)
	jne .L2
	ret
