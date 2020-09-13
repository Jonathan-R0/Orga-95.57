.globl main

/* OJO, ¡¡¡¡¡¡ESTÁ SIN TERMINAR!!!!!! :[ */

main:
	push  %ebx
/*	xorl %ebx, %ebx <- El %ebx es caller saved => pal stack se  va */
	xorl %ebx, %ebx
	xorl %edx, %edx
	movl 8(%esp), %edi  # Por lo el %ebx que
	movl 12(%esp), %esi  # pusheamos a la pila
	jmp .loop_cond

.loop:

/*	movl (%esi, %ebx, 4), %eax En 32 bits tenemos que */
/*	call strlen                pasar los args por el stack */

	/* Además no es la mejor idea del mundo usar el %eax así teniendo en cuenta que el return de strlen vendrá por ahí... */

	movl (%esi,%ebx,4), %edx
	pushl %edx
	call strlen

	cmpl $8, %eax
	jne .loop_cond
	
	pushl %eax
	call puts
	subl $4, %esp

.loop_cond:
	incl %ebx
	cmpl %ebx, %edi
	jae .loop
	
	popl %ebx
	popl %edx
	xorl %eax, %eax
	ret
