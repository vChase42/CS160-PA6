.data
printstr: .asciz "%d\n"

.text
.globl Main_main
classA_inc:
#preamble
push %ebp
mov %esp, %ebp
sub $32, %esp
push %ebx
push %esi
push %edi
push $2
mov 8(%ebp), %ebx
push 0(%ebx)
pop %eax
pop %ecx
mul %ecx
push %eax
mov 8(%ebp), %ebx
pop 0(%ebx)
push $1
mov 8(%ebp), %ebx
push 4(%ebx)
pop %ebx
pop %esi
add %esi, %ebx
push %ebx
mov 8(%ebp), %ebx
pop 4(%ebx)
#prologue
pop %edi
pop %esi
pop %ebx
mov %ebp, %esp
pop %ebp
ret
Main_main:
#preamble
push %ebp
mov %esp, %ebp
sub $32, %esp
push %ebx
push %esi
push %edi
push $2
call malloc
add $4, %esp
push %eax
pop -4(%ebp)
push $2
mov -4(%ebp), %ebx
pop 0(%ebx)
push $3
mov -4(%ebp), %ebx
pop 4(%ebx)
mov -4(%ebp), %ebx
push 0(%ebx)
#PRINT
push $printstr
call printf
mov -4(%ebp), %ebx
push 4(%ebx)
#PRINT
push $printstr
call printf
push $0
pop -8(%ebp)
DOWHILE_0:
push %eax
push %ecx
push %edx
push -4(%ebp)
call classA_inc
add $4, %esp
pop %edx
pop %ecx
pop %ebx
mov %ebx, %eax
mov -4(%ebp), %ebx
push 0(%ebx)
#PRINT
push $printstr
call printf
mov -4(%ebp), %ebx
push 4(%ebx)
#PRINT
push $printstr
call printf
push $1
push -8(%ebp)
pop %ebx
pop %esi
add %esi, %ebx
push %ebx
pop -8(%ebp)
push -8(%ebp)
push $5
pop %esi
pop %ebx
cmp %ebx, %esi
jg GT_1
push $0
jmp END_GT_2
GT_1:
push $1
END_GT_2:
pop %ebx
cmp $1, %ebx
je DOWHILE_0
#prologue
pop %edi
pop %esi
pop %ebx
mov %ebp, %esp
pop %ebp
ret
leave
