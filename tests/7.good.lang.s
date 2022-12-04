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
push $1
push -8(%ebp)
pop %ebx
pop %esi
add %esi, %ebx
push %ebx
pop -4(%ebp)
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
push $0
#PRINT
push $printstr
call printf
jmp END_3
FALSE_2:
push $1
#PRINT
push $printstr
call printf
END_3:
#Done IF statement
push $2
push -4(%ebp)
pop %esi
pop %ebx
cmp %ebx, %esi
je GE_4
push $0
jmp END_GE_5
GE_4:
push $1
END_GE_5:
#IF STATEMENT
popl %ebx
mov $0, %esi 
cmp %ebx, %esi
JE FALSE_6
push $2
#PRINT
push $printstr
call printf
jmp END_7
FALSE_6:
push $3
#PRINT
push $printstr
call printf
END_7:
#Done IF statement
push -8(%ebp)
push $3
pop %esi
pop %ebx
cmp %ebx, %esi
jg GT_8
push $0
jmp END_GT_9
GT_8:
push $1
END_GT_9:
push -4(%ebp)
push $3
pop %esi
pop %ebx
cmp %ebx, %esi
jg GT_10
push $0
jmp END_GT_11
GT_10:
push $1
END_GT_11:
pop %ebx
pop %esi
cmp %ebx, %esi
jne AND_12
push %ebx
jmp END_AND_13
AND_12:
push $0
END_AND_13:
#IF STATEMENT
popl %ebx
mov $0, %esi 
cmp %ebx, %esi
JE FALSE_14
push $4
#PRINT
push $printstr
call printf
jmp END_15
FALSE_14:
push $5
#PRINT
push $printstr
call printf
END_15:
#Done IF statement
push -8(%ebp)
push $3
pop %esi
pop %ebx
cmp %ebx, %esi
jg GT_16
push $0
jmp END_GT_17
GT_16:
push $1
END_GT_17:
push -4(%ebp)
push $3
pop %esi
pop %ebx
cmp %ebx, %esi
jg GT_18
push $0
jmp END_GT_19
GT_18:
push $1
END_GT_19:
pop %ebx
pop %esi
cmp %ebx, %esi
jne OR_20
push %ebx
jmp END_OR_21
OR_20:
push $1
END_OR_21:
#IF STATEMENT
popl %ebx
mov $0, %esi 
cmp %ebx, %esi
JE FALSE_22
push $6
#PRINT
push $printstr
call printf
jmp END_23
FALSE_22:
push $7
#PRINT
push $printstr
call printf
END_23:
#Done IF statement
#prologue
pop %edi
pop %esi
pop %ebx
mov %ebp, %esp
pop %ebp
ret
leave
