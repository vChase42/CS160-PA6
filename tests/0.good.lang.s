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
pop %ebx
mov $0, %esi
cmp %ebx, %esi
je false_0
push $0
jmp end_1
false_0:
push $1
pop %ebx
mov $0, %esi
cmp %ebx, %esi
je false_2
push $0
jmp end_3
false_2:
push $1
end_3:
end_1:
#PRINT
push $printstr
call printf
push $1
pop %ebx
mov $0, %esi
cmp %ebx, %esi
je false_6
push $0
jmp end_7
false_6:
push $1
end_7:
pop %ebx
mov $0, %esi
cmp %ebx, %esi
je false_4
push $0
jmp end_5
false_4:
push $1
end_5:
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
