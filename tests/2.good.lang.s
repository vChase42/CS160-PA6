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
push $1
push $2
push $6
mov $0, %edx
pop %eax
pop %ecx
div %ecx
push %eax
push $5
pop %ebx
pop %esi
add %esi, %ebx
push %ebx
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
