	.file	"test.c"
	.text
	.globl	fun
	.type	fun, @function
fun:
.LFB0:
	.cfi_startproc
	endbr64
	movq	%rsi, %r8
	leaq	(%rsi,%rdx), %rsi
	shrq	%rsi
	movq	%rsi, %rax
	movl	(%rdi,%rsi,4), %r9d
	cmpl	%ecx, %r9d
	je	.L6
	jle	.L3
	movq	%rsi, %rdx
	movq	%r8, %rsi
.L3:
	cmpq	%rdx, %rsi
	je	.L4
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	call	fun
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
.L4:
	movq	$-1, %rax
	ret
.L6:
	ret
	.cfi_endproc
.LFE0:
	.size	fun, .-fun
	.ident	"GCC: (Ubuntu 9.3.0-10ubuntu2) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
