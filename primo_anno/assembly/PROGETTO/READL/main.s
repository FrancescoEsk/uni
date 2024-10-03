# file main
.section .data

str:
    .ascii "10,9,121,2\n"

.section .text
    .global _start

_start:
    leal str, %eax
    movl $0, %ebx
    call readl
    call printfd

    leal str, %eax
    movl $1, %ebx
    call readl
    call printfd

    leal str, %eax
    movl $2, %ebx
    call readl
    call printfd

    leal str, %eax
    movl $3, %ebx
    call readl
    call printfd

    jmp exit

exit:
    movl $1, %eax 
    xorl %ebx, %ebx # codice di uscita (0)
    int $0x80


