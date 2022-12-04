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
push 12(%ebp)
push 12(%ebp)
pop %eax
pop %ecx
mul %ecx
push %eax
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
push $1
pop -4(%ebp)
push $2
pop -8(%ebp)
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
#PRINT
push $printstr
call printf
push %eax
push %ecx
push %edx
push $6
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
push -8(%ebp)
push -4(%ebp)
pop %ebx
pop %esi
add %esi, %ebx
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
