	.file	"test.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"The sizes of a is: %ld\n"
.LC1:
	.string	"The sizes of b is: %ld\n"
.LC2:
	.string	"The sizes of u is: %ld\n"
.LC3:
	.string	"checc: %ld\n"
	.text
	.globl	partA
	.type	partA, @function
partA:
.LFB21:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$16, %edx
	leaq	.LC0(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movl	$40, %edx
	leaq	.LC1(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movl	$8, %edx
	leaq	.LC2(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movl	$32, %edx
	leaq	.LC3(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE21:
	.size	partA, .-partA
	.globl	get_a_x
	.type	get_a_x, @function
get_a_x:
.LFB22:
	.cfi_startproc
	endbr64
	movl	(%rdi), %eax
	ret
	.cfi_endproc
.LFE22:
	.size	get_a_x, .-get_a_x
	.globl	get_bs_x
	.type	get_bs_x, @function
get_bs_x:
.LFB23:
	.cfi_startproc
	endbr64
	movsbq	3(%rdi), %rax
	ret
	.cfi_endproc
.LFE23:
	.size	get_bs_x, .-get_bs_x
	.globl	get_bv_x
	.type	get_bv_x, @function
get_bv_x:
.LFB24:
	.cfi_startproc
	endbr64
	movswq	18(%rdi), %rax
	ret
	.cfi_endproc
.LFE24:
	.size	get_bv_x, .-get_bv_x
	.globl	get_d_x
	.type	get_d_x, @function
get_d_x:
.LFB25:
	.cfi_startproc
	endbr64
	movzbl	4(%rdi), %eax
	ret
	.cfi_endproc
.LFE25:
	.size	get_d_x, .-get_d_x
	.globl	main
	.type	main, @function
main:
.LFB26:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$0, %eax
	call	partA
	movl	$0, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE26:
	.size	main, .-main
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
