ma:
    movq %rdx, %r9
    leaq -1(%rdx), %r8
    jmp .L2
.L3:
    addq (%rdi,%rcx,8), %rax # En la primera iteración vemos que lee v[n] en vez de v[i-j] => ¡Incorrecta!
    subq $1, %rcx
    jmp .L4
.L5:
    movq %r9, %rcx
    movl $0, %eax
.L4:
    testq %rcx, %rcx
    jne .L3
    movl $0, %edx
    divq %r9
    movq %rax, (%rdi,%r8,8)
    addq $1, %r8
.L2:
    cmpq %rsi, %r8
    jb .L5
    movq %rsi, %rax
    subq %r9, %rax
    ret