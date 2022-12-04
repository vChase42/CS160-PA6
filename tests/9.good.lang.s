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
push $0
pop -4(%ebp)
push $1
pop -8(%ebp)
push $0
pop -12(%ebp)
WHILE_0:
push -4(%ebp)
push $8
pop %esi
pop %ebx
cmp %ebx, %esi
jge GTE_2
push $0
jmp END_GTE_3
GTE_2:
push $1
END_GTE_3:
pop %ebx
cmp $1, %ebx
jne WHILE_END_1
push $0
push $2
push $2
push -4(%ebp)
mov $0, %edx
pop %eax
pop %ecx
div %ecx
push %eax
pop %eax
pop %ecx
mul %ecx
push %eax
push -4(%ebp)
pop %ebx
pop %esi
sub %esi, %ebx
push %ebx
pop %esi
pop %ebx
cmp %ebx, %esi
jg GT_4
push $0
jmp END_GT_5
GT_4:
push $1
END_GT_5:
pop -12(%ebp)
push $1
push -4(%ebp)
pop %ebx
pop %esi
add %esi, %ebx
push %ebx
pop -4(%ebp)
push -12(%ebp)
#IF STATEMENT
popl %ebx
mov $0, %esi 
cmp %ebx, %esi
JE FALSE_6
push $2
push -8(%ebp)
pop %eax
pop %ecx
mul %ecx
push %eax
pop -8(%ebp)
jmp END_7
FALSE_6:
push $1
push -8(%ebp)
pop %ebx
pop %esi
add %esi, %ebx
push %ebx
pop -8(%ebp)
END_7:
#Done IF statement
push -8(%ebp)
#PRINT
push $printstr
call printf
jmp WHILE_0
WHILE_END_1:
#prologue
pop %edi
pop %esi
pop %ebx
mov %ebp, %esp
pop %ebp
ret
leave
