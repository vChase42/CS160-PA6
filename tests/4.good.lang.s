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
push $4
push $6
pop %ebx
pop %esi
sub %esi, %ebx
push %ebx
pop -4(%ebp)
push $1
push $4
push -4(%ebp)
pop %eax
pop %ecx
mul %ecx
push %eax
pop %ebx
pop %esi
sub %esi, %ebx
push %ebx
pop -8(%ebp)
push $2
push -8(%ebp)
push -4(%ebp)
pop %eax
pop %ecx
mul %ecx
push %eax
mov $0, %edx
pop %eax
pop %ecx
div %ecx
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
