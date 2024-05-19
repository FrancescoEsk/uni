# file main
.section .data

str:
    .ascii "10,9,121,2\n"

stackI:
    .long 0

.section .text
    .global _start

_start:
    movl $1, %eax
    movl $2, %ebx
    movl $3, %ecx
    pushl %eax
    pushl %ebx
    pushl %ecx

    xorl %eax, %eax
    xorl %ebx, %ebx
    xorl %ecx, %ecx

    movl %esp, stackI

    addl $12, %esp

while:
    cmpl stackI, %esp
    je finish
    popl %eax
    call printfd
    pushl %eax
    subl $4, %esp
    jmp while

finish:
    # movl stackI, %esp
    jmp exit

exit:
    movl $1, %eax 
    xorl %ebx, %ebx # codice di uscita (0)
    int $0x80


