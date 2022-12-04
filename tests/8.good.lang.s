.data
printstr: .asciz "%d\n"

.text
.globl Main_main
Main_main:
#preamble
push %ebp
mov %esp, %ebp
sub $32, %esp
push %ebx
push %esi
push %edi
push $0
pop -4(%ebp)
push $0
pop -8(%ebp)
WHILE_0:
push -4(%ebp)
push $5
pop %esi
pop %ebx
cmp %ebx, %esi
jg GT_2
push $0
jmp END_GT_3
GT_2:
push $1
END_GT_3:
pop %ebx
cmp $1, %ebx
jne WHILE_END_1
push $2
push -4(%ebp)
push -8(%ebp)
pop %eax
pop %ecx
mul %ecx
push %eax
pop %ebx
pop %esi
add %esi, %ebx
push %ebx
pop -8(%ebp)
push $1
push -4(%ebp)
pop %ebx
pop %esi
add %esi, %ebx
push %ebx
pop -4(%ebp)
push -8(%ebp)
#PRINT
push $printstr
call printf
jmp WHILE_0
WHILE_END_1:
#prologue
pop %edi
pop %esi
pop %ebx
mov %ebp, %esp
pop %ebp
ret
leave
