	.file	"test.c"
	.text
	.globl	fun1
	.type	fun1, @function
fun1:
.LFB0:
	.cfi_startproc
	endbr32
	movl	4(%esp), %edx
	movl	8(%esp), %eax
	cmpl	%eax, %edx
	jge	.L2
	movl	%edx, %eax
.L2:
	ret
	.cfi_endproc
.LFE0:
	.size	fun1, .-fun1
	.globl	fun2
	.type	fun2, @function
fun2:
.LFB1:
	.cfi_startproc
	endbr32
	movl	4(%esp), %eax
	movl	8(%esp), %edx
	cmpl	%eax, %edx
	jge	.L4
	movl	%edx, %eax
.L4:
	ret
	.cfi_endproc
.LFE1:
	.size	fun2, .-fun2
	.globl	fun3
	.type	fun3, @function
fun3:
.LFB2:
	.cfi_startproc
	endbr32
	movl	4(%esp), %eax
	movl	8(%esp), %edx
	cmpl	%eax, %edx
	jbe	.L6
	movl	%edx, %eax
.L6:
	ret
	.cfi_endproc
.LFE2:
	.size	fun3, .-fun3
	.globl	xd
	.type	xd, @function
xd:
.LFB3:
	.cfi_startproc
	endbr32
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	pushl	$0
	.cfi_def_cfa_offset 12
	pushl	$0
	.cfi_def_cfa_offset 16
	call	fun1
	addl	$8, %esp
	.cfi_def_cfa_offset 8
	movl	%eax, %ebx
	pushl	$0
	.cfi_def_cfa_offset 12
	pushl	$0
	.cfi_def_cfa_offset 16
	call	fun2
	addl	$8, %esp
	.cfi_def_cfa_offset 8
	addl	%eax, %ebx
	pushl	$0
	.cfi_def_cfa_offset 12
	pushl	$0
	.cfi_def_cfa_offset 16
	call	fun3
	addl	$8, %esp
	.cfi_def_cfa_offset 8
	addl	%ebx, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE3:
	.size	xd, .-xd
	.ident	"GCC: (Ubuntu 9.3.0-10ubuntu2) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 4
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 4
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 4
4:
