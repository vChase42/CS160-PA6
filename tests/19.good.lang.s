.data
printstr: .asciz "%d\n"

.text
.globl Main_main
classA_classA:
#preamble
push %ebp
mov %esp, %ebp
sub $32, %esp
push %ebx
push %esi
push %edi
push 12(%ebp)
mov 8(%ebp), %ebx
pop 0(%ebx)
push 16(%ebp)
mov 8(%ebp), %ebx
pop 4(%ebx)
#prologue
pop %edi
pop %esi
pop %ebx
mov %ebp, %esp
pop %ebp
ret
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
push $4
push $3
push %eax
call classA_classA
add $12, %esp
push %eax
pop -4(%ebp)
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
push 4(%ebx)
mov -4(%ebp), %ebx
push 0(%ebx)
pop %eax
pop %ecx
mul %ecx
push %eax
#PRINT
push $printstr
call printf
#prologue
pop %edi
pop %esi
pop %ebx
mov %ebp, %esp
pop %ebp
ret
leave
