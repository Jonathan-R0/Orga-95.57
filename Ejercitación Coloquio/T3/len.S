.globl my_strlen

my_strlen:
	xorq %rax,%rax
	xorq %rbx,%rbx
	
	cmpq $0,%rax	
	jne .L1
	
	ret

.L1:
	incq %rbx
	cmpq $0,%rax
	jne .L1
	ret
