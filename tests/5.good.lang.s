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
push $5
push $4
push $3
push $2
push $1
pop %ebx
pop %esi
add %esi, %ebx
push %ebx
pop %ebx
pop %esi
add %esi, %ebx
push %ebx
pop %ebx
pop %esi
sub %esi, %ebx
push %ebx
pop %ebx
pop %esi
add %esi, %ebx
push %ebx
pop -4(%ebp)
push -4(%ebp)
push -4(%ebp)
push -4(%ebp)
pop %eax
pop %ecx
mul %ecx
push %eax
pop %eax
pop %ecx
mul %ecx
push %eax
pop -8(%ebp)
push -4(%ebp)
push $5
pop %eax
pop %ecx
mul %ecx
push %eax
push -4(%ebp)
push $5
mov $0, %edx
pop %eax
pop %ecx
div %ecx
push %eax
pop %ebx
pop %esi
add %esi, %ebx
push %ebx
pop -12(%ebp)
push $2
push $1
push -12(%ebp)
pop %ebx
pop %esi
sub %esi, %ebx
push %ebx
push $1
push -12(%ebp)
pop %ebx
pop %esi
add %esi, %ebx
push %ebx
pop %eax
pop %ecx
mul %ecx
push %eax
mov $0, %edx
pop %eax
pop %ecx
div %ecx
push %eax
pop -4(%ebp)
push $100
push -4(%ebp)
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
pop -8(%ebp)
push -4(%ebp)
push -8(%ebp)
pop %ebx
pop %esi
add %esi, %ebx
push %ebx
push -4(%ebp)
push -8(%ebp)
pop %ebx
pop %esi
sub %esi, %ebx
push %ebx
pop %eax
pop %ecx
mul %ecx
push %eax
pop -12(%ebp)
push -4(%ebp)
#PRINT
push $printstr
call printf
push -8(%ebp)
#PRINT
push $printstr
call printf
push -12(%ebp)
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
