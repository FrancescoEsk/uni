#include <stdio.h>
#include <stdlib.h>
/*
ALLOCAZIONE VARIABILI AUTOMATICA o STATICA
--> STACK

--> L'allocazione avviene in modo automatico quando si entra in un blocco di codice
    e viene riallocata automaticamente quando si esce dal blocco

--> richiedono di conoscere la dimensione delle variabili in tempo di compilazione

ALLOCAZIONE DINAMICA DELLA MEMORIA
Lo spazio necessario per memorizzare certe variabili è noto solo durante l'esecuzione del programma, gestite nell'heap.
richiede funzione specifiche (ed esplicite) per allocare e LIBERARE la memoria

!!! <stdlib.h> !!!

AVVIENE TRAMITE DUE FUNZIONI
    CALLOC();
    --> 2 ARGOMENTI: - # elementi da riservare
                     - dim di ciascun elemento in byte

    --> l'area di memoria è posta a 0

    --> restituisce un puntatore all'inizio dell'area di memoria allocata
        (tipo void)

    MALLOC();
    --> 1 ARGOMENTO: # totale di byte

    --> non pone a 0 la memoria

    --> restituisce un puntatore all'inizio dell'area di memoria allocata
        (tipo void)

DIMENSIONE IN BYTE
    SIZEOF(); --> restituisce la dimensione in byte di un elemento passato come parametro

    PARAMETRI: 
        - variabile semplice
        - array
        - tipo di dato
        - tipo di dato derivato (struct)
        - puntatore

OPERATORI: valutati a tempo di compilazione
--> il risultato del calcolo sostituisce l'operatore nel compilato

NB
Se si richiede più memoria di quella disponibile 
--> restituiscono un puntatore NULLO

Va quindi controllato il risultato dell'allocazione

if(ptr != NULL){ ... }

!!! LIBERARE LA MEMORIA --> tramite FREE(ptr); !!!
*/
typedef struct{
    int a, b;
    char c;
    int v[10];
} date;

int main(void){
    int x;
    sizeof(x); // # di byte necessari per memorizzare un intero

    int a[10];
    sizeof(a); // # di byte necessari per memorizzare l'intero array

    sizeof(int); // # di byte necessari per memorizzare un intero

    sizeof(date); // # di byte per mem una specifica struct

    sizeof(int*); // # di byte per un puntatore ad intero
    int* p1, p2;
    p1 = calloc(1000, sizeof(int)); // eseguo cast a puntatore intero, siccome danno come risultato tipo void
    p2 = malloc(1000*sizeof(int)); // entrambi puntano all'inizio dell'area di memoria allocata

    if (p1 != NULL && p2 != NULL){
        // ...
        free(p1); // libero la memoria dopo averla utilizzata
        free(p2);
    } else {
        printf("Memoria piena!\n");
    }
    
    return 0;
}