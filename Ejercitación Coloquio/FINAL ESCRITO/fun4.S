ma:
    movq %rdx, %r9
    leaq -1(%rdx), %r8
    jmp .L2
.L3:
    movq %r8, %rdx
    subq %rcx, %rdx
    addq (%rdi,%rdx,8), %rax
    addq $1, %rcx
    jmp .L4
.L5:
    movl $0, %eax
    movl $0, %ecx
.L4:
    cmpq %r9, %rcx
    jb .L3
    movl $0, %edx
    divq %r9
    movq %r8, %rdx
    subq %rcx, %rdx
    movq %rax, (%rdi,%rdx,8)
    addq $1, %r8
.L2:
    cmpq %rsi, %r8
    jb .L5
    rep ret # Resulta ser exactamente lo mismo que la sexta opción, pero le falta mover l-n a %rax.