.data
printstr: .asciz "%d\n"

.text
.globl Main_main
classA_f0:
#preamble
push %ebp
mov %esp, %ebp
sub $32, %esp
push %ebx
push %esi
push %edi
push $2
push $2
push 12(%ebp)
mov $0, %edx
pop %eax
pop %ecx
div %ecx
push %eax
pop %eax
pop %ecx
mul %ecx
push %eax
push 12(%ebp)
pop %ebx
pop %esi
sub %esi, %ebx
push %ebx
pop -8(%ebp)
push $1
push -8(%ebp)
pop %esi
pop %ebx
cmp %ebx, %esi
je GE_0
push $0
jmp END_GE_1
GE_0:
push $1
END_GE_1:
#IF STATEMENT
popl %ebx
mov $0, %esi 
cmp %ebx, %esi
JE FALSE_2
push $1
push 12(%ebp)
push 12(%ebp)
pop %eax
pop %ecx
mul %ecx
push %eax
pop %ebx
pop %esi
sub %esi, %ebx
push %ebx
pop -4(%ebp)
jmp END_3
FALSE_2:
push $2
push 12(%ebp)
mov $0, %edx
pop %eax
pop %ecx
div %ecx
push %eax
pop -4(%ebp)
END_3:
#Done IF statement
push -4(%ebp)
pop %eax
#prologue
pop %edi
pop %esi
pop %ebx
mov %ebp, %esp
pop %ebp
ret
classA_doAll:
#preamble
push %ebp
mov %esp, %ebp
sub $32, %esp
push %ebx
push %esi
push %edi
push %eax
push %ecx
push %edx
push %eax
push %ecx
push %edx
push %eax
push %ecx
push %edx
push %eax
push %ecx
push %edx
push %eax
push %ecx
push %edx
push $5
push 8(%ebp)
call classA_f0
add $8, %esp
pop %edx
pop %ecx
pop %ebx
push %eax
mov %ebx, %eax
push 8(%ebp)
call classA_f0
add $8, %esp
pop %edx
pop %ecx
pop %ebx
push %eax
mov %ebx, %eax
push 8(%ebp)
call classA_f0
add $8, %esp
pop %edx
pop %ecx
pop %ebx
push %eax
mov %ebx, %eax
push 8(%ebp)
call classA_f0
add $8, %esp
pop %edx
pop %ecx
pop %ebx
push %eax
mov %ebx, %eax
push 8(%ebp)
call classA_f0
add $8, %esp
pop %edx
pop %ecx
pop %ebx
push %eax
mov %ebx, %eax
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
Main_main:
#preamble
push %ebp
mov %esp, %ebp
sub $32, %esp
push %ebx
push %esi
push %edi
push %eax
push %ecx
push %edx
push -4(%ebp)
call classA_doAll
add $4, %esp
pop %edx
pop %ecx
pop %ebx
mov %ebx, %eax
#prologue
pop %edi
pop %esi
pop %ebx
mov %ebp, %esp
pop %ebp
ret
leave
