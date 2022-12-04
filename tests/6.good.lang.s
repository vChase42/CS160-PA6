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
pop -4(%ebp)
push $1
push -4(%ebp)
pop %ebx
pop %esi
add %esi, %ebx
push %ebx
pop -8(%ebp)
push $2
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
#PRINT
push $printstr
call printf
FALSE_2:
#Done IF statement
push $0
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
