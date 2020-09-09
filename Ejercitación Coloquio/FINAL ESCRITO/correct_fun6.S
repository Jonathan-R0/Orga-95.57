ma: # ¡CORRECTA! :]
    movq %rdx, %r9     # %r9 ← n
    leaq -1(%rdx), %r8 # %r8 ← n-1 = i
    jmp .L2
.L3:
    movq %r8, %rdx  # %rdx ← i
    subq %rcx, %rdx # %rdx ← i-j
    addq (%rdi,%rdx,8), %rax # %rax ← v[i-j] (como nos movemos 8*(i-j) bytes, saltamos i-j longs)
    addq $1, %rcx   # %rcx ← j++
    jmp .L4
.L5:
    movl $0, %eax
    movl $0, %ecx
.L4:
    cmpq %r9, %rcx  # if (j < n) => GOTO .L3
    jb .L3
    movl $0, %edx
    divq %r9        # %rax ← %rax/n 
    movq %r8, %rdx 
    subq %rcx, %rdx # %rax ← i-j
    movq %rax, (%rdi,%rdx,8)
    addq $1, %r8
.L2:
    cmpq %rsi, %r8 # if (i < l) => GOTO .L5
    jb .L5
    movq %rsi, %rax 
    subq %r9, %rax # %rax ← l-n
ret