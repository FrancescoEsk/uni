.section .data

new_line_char:
    .byte 10

.section .text
.align 4

.global _start

_start:
    movl %esp, %ebp

ancora:
    addl $4, %esp

    movl (%esp), %eax

    testl %eax, %eax

    jz fine_ancora
    call stampa_parametro

    jmp ancora

fine_ancora: 
    movl $1, %eax
    movl $0, %ebx
    int $0x80

.type stampa_parametro, @function

stampa_parametro:
    pushl %ebp
    movl  %esp, %ebp
    movl  8(%ebp), %ecx

    xorl  %edx, %edx

conteggio_caratteri:
    movb (%ecx,%edx), %al
    testb %al, %al
    jz finito_conteggio
    incl %edx
    