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
push 16(%ebp)
#IF STATEMENT
popl %ebx
mov $0, %esi 
cmp %ebx, %esi
JE FALSE_0
push 12(%ebp)
push 12(%ebp)
pop %eax
pop %ecx
mul %ecx
push %eax
pop -4(%ebp)
jmp END_1
FALSE_0:
push $2
push 12(%ebp)
mov $0, %edx
pop %eax
pop %ecx
div %ecx
push %eax
pop -4(%ebp)
END_1:
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
push $0
pop -4(%ebp)
push $2
pop -8(%ebp)
WHILE_2:
push -4(%ebp)
push $5
pop %esi
pop %ebx
cmp %ebx, %esi
jg GT_4
push $0
jmp END_GT_5
GT_4:
push $1
END_GT_5:
pop %ebx
cmp $1, %ebx
jne WHILE_END_3
push %eax
push %ecx
push %edx
push -4(%ebp)
push $2
pop %esi
pop %ebx
cmp %ebx, %esi
jge GTE_6
push $0
jmp END_GTE_7
GTE_6:
push $1
END_GTE_7:
push -8(%ebp)
push 8(%ebp)
call classA_f0
add $12, %esp
pop %edx
pop %ecx
pop %ebx
push %eax
mov %ebx, %eax
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
jmp WHILE_2
WHILE_END_3:
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
