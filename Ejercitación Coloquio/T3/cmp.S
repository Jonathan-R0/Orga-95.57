.globl my_strcmp

# A -> %RDI
# B -> %RSI
# strlen(A) -> %RBX

my_strcmp:
	
	pushq %rdi
	call my_strlen 
	popq %rdi

	movq %rax,%rcx
	xorq %rax,%rax
	cmpb $0,(%rdi)
	je .L1
	cmpb $0,(%rsi)
	je .L2	
	jmp .loop

	ret

.inc:
	incq %rdi
	incq %rsi
	subq $1,%rcx
	cmpq $0,%rcx # %RCX == 0
	je .L3
.loop: 
	movb (%rsi),%bl
	cmpb %bl,(%rdi)
	je .inc
	jl .end1
	jg .end2
	ret

.end1:
	movq %rcx,%rax
	imulq $-1,%rax
	ret
.end2:
	movq %rcx,%rax
	ret

.L1:
	cmpb $0,(%rsi)
	jne .L3	
	decq %rax
	ret

.L2:
	cmpb $0,(%rdi)
	jne .L3	
	incq %rax
	ret

.L3:
	xorq %rax,%rax
	ret
