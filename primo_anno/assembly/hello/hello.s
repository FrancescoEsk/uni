# Nome file
# ----------
# hello.s
# 
# Istruzioni per la compilazione
# ------------------------------
# as -o hello.o hello.s
# ld -o hello hello.o
# 
# Funzionalita'
# -------------
# Stampa a video la scritta "Ciao Mondo!" e va a capo
# 
# Commenti
# --------
# Il carattere # indica l'inizio di un commento.

# http://asm.sourceforge.net/syscall.html


.section .data                 # sezione variabili globali

hello:                         # etichetta
      .ascii "Ciao Mondo!\n"   # stringa costante

hello_len:
      .long . - hello          # lunghezza della stringa in byte

.section .text                 # sezione istruzioni
      .global _start           # punto di inizio del programma

_start:
      movl $4, %eax            # Carica il codice della system call WRITE
                               # in eax per scrivere la stringa
                               # ”Ciao Mondo!” a video.
      
      movl $1, %ebx            # Mette a 1 il contenuto di EBX
                               # Quindi ora EBX=1. 1 è il
                               # primo parametro per la write e
                               # serve per indicare che vogliamo
                               # scrivere nello standard output (scrivere a console)

      leal hello, %ecx         # Secondo parametro della write
                               # Carica in ECX l’indirizzo di
                               # memoria associato all’etichetta
                               # hello, ovvero il puntatore alla
                               # stringa “Ciao Mondo!\n” da stampare.

      movl hello_len, %edx     # Terzo parametro della write
                               # carica in EDX la lunghezza della
                               # stringa “Ciao Mondo!\n”. Questo perchè altrimenti stamperebbe tutta la memoria da hello in poi

      int $0x80                # esegue la system call write
                               # tramite l’interrupt 0x80 generico

      movl $1, %eax            # Mette a 1 il registro EAX
                               # 1 è il codice della system call exit
      
      xorl %ebx, %ebx          # azzera EBX. Contiene il codice di
                               # ritorno della exit

      int $0x80                # esegue la system call exit

