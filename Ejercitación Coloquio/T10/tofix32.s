.globl main

main:
	xorl %ebx, %ebx
	movl 4(%esp), %esi
	movl 8(%esp), %edi
	mp .loop_cond

.loop:
	movl (%edi, %ebx, 4), %eax

	call strlen
	cmpl $8, %eax
	jne .loop_cond
	
	push %eax
	call puts
	subl $4, %esp

.loop_cond:
	incl %ebx
	cmpl %ebx, %esi
	jae .loop
	
	movl $0, %eax
	ret
