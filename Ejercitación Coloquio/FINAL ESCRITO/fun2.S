ma:
    movq %rdx, %r8
    leaq -1(%rdx), %r9
    jmp .L2
.L3:
    addq (%rdi,%rcx,8), %rax # En la primera iteración vemos que lee v[0] => ¡Incorrecta!
    addq $1, %rcx
    jmp .L4
.L5:
    movl $0, %eax
    movl $0, %ecx
.L4:
    cmpq %r8, %rcx
    jb .L3
    movl $0, %edx
    divq %r8
    movq %rax, (%rdi,%r9,8)
    addq $1, %r9
.L2:
    cmpq %rsi, %r9
    jb .L5
    movq %rsi, %rax
    subq %r8, %rax
    ret
