ma:
    movq %rdx, %r8
    leaq -1(%rdx), %r10
    jmp .L2
.L3: # MUY probablemente esta opción es incorrecta ya que este código divide en cada operación, 
     # lo que resulta ser más ineficiente que dividir al final del loop interno => El compilador 
     # no puede haber generado este archivo.
    movq %r10, %rdx
    subq %rcx, %rdx
    movq (%rdi,%rdx,8), %rax
    movl $0, %edx
    divq %r8
    addq %rax, %r9
    addq $1, %rcx
    jmp .L4
.L5:
    movl $0, %r9d
    movl $0, %ecx
.L4:
    cmpq %r8, %rcx
    jb .L3
    movq %r10, %rdx
    subq %rcx, %rdx
    movq %r9, (%rdi,%rdx,8)
    addq $1, %r10
.L2:
    cmpq %rsi, %r10
    jb .L5
    movq %rsi, %rax
    subq %r8, %rax
    ret