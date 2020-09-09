ma:
    movq %rdx, %r9
    movl $0, %r8d
    jmp .L2
.L3:
    leaq (%r8,%rcx), %rdx # En la primera iteración vemos que lee v[0] => ¡Incorrecta!
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
    movq %rax, (%rdi,%r8,8)
    addq $1, %r8
.L2:
    movq %rsi, %rax
    subq %r9, %rax
    cmpq %rax, %r8
    jb .L5
    rep ret