.globl f
.globl g

f:
   movl $0, %eax           /*-> Valor a devolver */
   jmp .L2
.L3:
   leaq (%rsi,%rdi,), %rdx /*-> t = a + b; */
   addq %rdx, %rax         /*-> result += t; */
   subq $1, %rdi
.L2:
   cmpq %rsi, %rdi         /*-> (a - b > 0) */
   jg .L3
   ret 

g:
   testq %rsi, %rsi /*----------------v       No queremos que se active el ZF ni el SF */
   jle .L8          /*-> Salta si (b <= 0) <= como producto de la comparación de testq. */
   movq %rsi, %rax
.L7:
   imulq %rdi, %rax  /*-> result *= a; */
   subq %rdi, %rsi
   testq %rsi, %rsi /*----------------v */
   jg .L7           /*-> No salta si (b <= 0) */
   ret
.L8:
   movq %rsi, %rax
   ret
