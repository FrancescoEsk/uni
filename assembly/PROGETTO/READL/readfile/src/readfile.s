.section .data
filename:
    .ascii "test.txt"    # Nome del file di testo da leggere
fd:
    .int 0               # File descriptor

buffer: .string ""       # Spazio per il buffer di input
newline: .byte 10        # Valore del simbolo di nuova linea
lines: .int 0            # Numero di linee

.section .bss

.section .text
    .global _start

# Apre il file
_open:
    movl $5, %eax        # syscall open
    movl $filename, %ebx # Nome del file
    movl $0, %ecx        # Modalità di apertura (O_RDONLY)
    int $0x80           # Interruzione del kernel

    # Se c'è un errore, esce
    cmpl $0, %eax
    jl _exit

    movl %eax, fd      # Salva il file descriptor in ebx

# Legge il file riga per riga
_read_loop:
    movl $3, %eax        # syscall read
    movl fd, %ebx        # File descriptor
    movl $buffer, %ecx   # Buffer di input
    movl $1, %edx        # Lunghezza massima
    int $0x80           # Interruzione del kernel

    cmpl $0, %eax        # Controllo se ci sono errori o EOF
    jle _close_file     # Se ci sono errori o EOF, chiudo il file
    
    # Controllo se ho una nuova linea
    movlb buffer, %al    # copio il carattere dal buffer ad AL
    cmpb newline, %al   # confronto AL con il carattere \n
    jne _print_line     # se sono diversi stampo la linea
    incw lines          # altrimenti, incremento il contatore

_print_line:
    # Stampa il contenuto della riga
    movl $4, %eax        # syscall write
    movl $1, %ebx        # File descriptor standard output (stdout)
    movl $buffer, %ecx   # Buffer di output
    int $0x80           # Interruzione del kernel

    jmp _read_loop      # Torna alla lettura del file

# Chiude il file
_close_file:
    movl $6, %eax        # syscall close
    movl %ebx, %ecx      # File descriptor
    int $0x80           # Interruzione del kernel

_exit:
    movl $1, %eax        # syscall exit
    xorl %ebx, %ebx      # Codice di uscita 0
    int $0x80           # Interruzione del kernel

_start:
    jmp _open          # Chiama la funzione per aprire il file

    # Fine programma
    jmp _exit

