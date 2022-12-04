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
push $2
call malloc
add $4, %esp
push %eax
pop -4(%ebp)
push $5
mov -4(%ebp), %ebx
pop 0(%ebx)
push $6
mov -4(%ebp), %ebx
pop 4(%ebx)
push $1
mov -4(%ebp), %ebx
push 4(%ebx)
mov -4(%ebp), %ebx
push 0(%ebx)
pop %eax
pop %ecx
mul %ecx
push %eax
pop %ebx
pop %esi
sub %esi, %ebx
push %ebx
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
