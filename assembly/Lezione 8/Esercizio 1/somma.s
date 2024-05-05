.section .data

titolo: # titolo programma
    .ascii "Programma che calcola la somma dei numeri 100, 33 e 68\n"
titolo_len:
    .long . - titolo

# 3 numeri da sommare
n1:
    .long 100

n2:
    .long 33

n3: 
    .long 68

somma: # var risultante
    .ascii "000\n"

# codice
.section .text
    .global _start

_start:
    # scrivo a video il titolo
    mov $4, %eax
    mov $1, %ebx # standard output
    leal titolo, %ecx # stringa da stampare
    mov titolo_len, %edx # lunghezza stringa
    int $0x80 

    mov n1, %ecx
    add n2, %ecx
    add n3, %ecx

    

    jmp exit

exit:
    mov $1, %eax 
    xorl %ebx, %ebx # codice di uscita (0)
    int $0x80

