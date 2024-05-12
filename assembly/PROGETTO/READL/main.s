# file main
.section .data

str:
    .ascii "010.09.121.2\n"

.section .text
    .global _start

_start:
    leal str, %eax
    movl $11, %ebx

    call readl
    
    call printfd

    jmp exit

exit:
    movl $1, %eax 
    xorl %ebx, %ebx # codice di uscita (0)
    int $0x80


