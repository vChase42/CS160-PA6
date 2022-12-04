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
push $5
push 8(%ebp)
call classA_f0
add $8, %esp
pop %edx
pop %ecx
pop %ebx
mov %ebx, %eax
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
mov %ebx, %eax
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
