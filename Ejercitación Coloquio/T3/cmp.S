.globl my_strcmp

# A -> %RDI
# B -> %RSI

my_strcmp:
	xorq %rax,%rax
	cmpq $0,(%rdi)
	jne .L1
	cmpq $0,(%rsi)
	jne .L2	

	ret

.L1:
	cmpq $0,(%rsi)
	jne .L3	
	movq $-1,%rax
	ret

.L2:
	cmpq $0,(%rdi)
	jne .L3	
	movq $1,%rax
	ret

.L3:
	xorq %rax,%rax
	ret
