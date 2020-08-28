.file "ffi.c"
.text
.globl ffi
.type ffi, @function
ffi:
.LFB0:##########################################
	.cfi_startproc
	movl m[0][0], aux // aux = m[0][0] -> %eax
	cmpl $35, n    // n <CMP> 35
	movl $34, z // -- z = RDX --
	cmovge z, n // n >= 35 => n = 34 => H = 34 (pues que n >= 35 es lo mismo que n > 34 en C).
	movl $0, i
	jmp .L3
.L5:
	leaq (i,i,2), z // T = 3i
	leaq (i,z,4), z // T = 13i
	leaq (m,T,4), z // T = 64i + m
	movl (T,j,4), z // T = m + 64i + 4j = m[i][j]
	movl z, X // -- X = R9 --
	sarl $31, X
	xorl X, z
	subl X, z
	cmpl z, aux
	cmovg z, aux
	addq $1, j // j++
	jmp .L6
.L9:
	movl $0, j
.L6:
	cmpq $12, j // j<13 -GOTO-> J5
	jbe .L5
	addq $1, i // i++
.L3:
	movslq n, z
	cmpq z, i // %r8 < %rdx -GOTO-> .L9
	jb .L9
	rep ret
	.cfi_endproc
.LFE0:##########################################
	.size ffi, .-ffi
	.ident "GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.11) 5.4.0 20160609"
	.section .note.GNU-stack,"",@progbits
