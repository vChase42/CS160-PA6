.data
printstr: .asciz "%d\n"

.text
.globl Main_main



Main_main:

    # jmp false_branch



    # cmp %ebx, %esi
    # je false_branch

    # push $8
    # push $printstr
    # call printf

    # false_branch:

    # push $4

    #ADD
    # mov $4, %eax
    # mov $5, %esi
    # add %esi, %eax
    # push %eax

    #MULTIPLY
    # mov $50, %eax
    # mov $6, %ecx
    # mul %ecx
    # push %eax

    #DIVISION
    # mov $0, %edx
    # mov $36, %eax
    # mov $6, %ecx
    # div %ecx
    # push %eax


    #AND
    # push $1
    # push $1
    # pop %ebx
    # pop %esi
    # cmp %ebx, %esi
    # jne false
    # push %ebx
    # jmp end
    # false:
    # push $0
    # end:

    #OR
    # push $0
    # push $0
    # pop %ebx
    # pop %esi
    # cmp %ebx, %esi
    # jne true
    # push %ebx
    # jmp end
    # true:
    # push $1
    # end:

    #NOT
    # push $1
    # pop %ebx
    # mov $0, %esi
    # cmp %ebx, %esi
    # jne true
    # push $1
    # jmp end
    # true:
    # push $0
    # end:


    # push %ebp
    # mov %esp, %ebp

    # call foo

    # mov %ebx, -8(%ebp)

    # sub $4, %ebp
    # mov -4(%ebp), %esi
    # add $4, %ebp
    # # add $4, %ebp

    # push %esi

    push %ebp
    push $printstr
    call printf
    
    push %esp
    push $printstr
    call printf
    # pop $eax
    leave
    ret
