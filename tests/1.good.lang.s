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
push $6
push $5
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
leave
