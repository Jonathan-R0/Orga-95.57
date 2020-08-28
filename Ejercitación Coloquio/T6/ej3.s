.file "ffi.c"
.text
.globl ffi
.type ffi, @function
ffi:
.LFB0:##########################################
	.cfi_startproc
	movl (%rdi), %eax // aux = m[0][0] -> %eax
	cmpl $35, %esi    // n <CMP> 35
	movl $34, %edx
	cmovge %edx, %esi // n >= 35 => n = 34 => H = 34 (pues que n >= 35 es lo mismo que n > 34 en C).
	movl $0, %r8d
	jmp .L3
.L5:
	leaq (%r8,%r8,2), %rdx // %rdx = z (del código C)
	leaq (%r8,%rdx,4), %rdx
	leaq (%rdi,%rdx,4), %rdx
	movl (%rdx,%rcx,4), %edx // Hasta acá se calcula z = m[i][j]
#########################################################################
	movl %edx, %r9d	// Acá se está calculando abs(x) = |x| = z
	sarl $31, %r9d  // dentro del ciclo, con el siguiente algorítmo:
	xorl %r9d, %edx
	subl %r9d, %edx // z = |x| = (x^y)-y con y = x >> 31 -> %r9
#########################################################################
	cmpl %edx, %eax
	cmovg %edx, %eax // aux > |x| => aux = z = |x| => Solo en las opción f) se calcula el abs(x) dentro del ciclo y se compara con z < aux.
	addq $1, %rcx // j++
	jmp .L6
.L9:
	movl $0, %ecx
.L6:
	cmpq $12, %rcx // j < 13 =GOTO=> .L5 => Esta es la comparación del for interno => K = 13
	jbe .L5
	addq $1, %r8 // i++
.L3:
	movslq %esi, %rdx
	cmpq %rdx, %r8 // %r8 < %rdx =GOTO=> .L9
	jb .L9
	rep ret
	.cfi_endproc
.LFE0:##########################################
	.size ffi, .-ffi
	.ident "GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.11) 5.4.0 20160609"
	.section .note.GNU-stack,"",@progbits
