#include <stdio.h>
/*
VARIABILI
    LOCALI : definite all'interno di una funzione (main o sottoprogramma)
    il suo valore può essere utilizzato solo all'interno della funzione in cui la var è definita.

    GLOBALI : definite all'esterno di qualunque funzione (prima di qualsiasi funzione)
    il suo valore può essere utilizzato da QUALSIASI funzione del programma

    -> qualsiasi funzione può modificarne il valore
!!! -> sono inizializzate con valore di default = 0 !!!

int array[10]; (GOLBALE) --> TUTTI GLI ELEMENTI = 0

ESEMPIO:
*/

// variabile globale
int MULTIPLIER = 1; // potrà essere utilizzata (r, w) da tutte le funzioni successive

void changeMULTIPLIER(int);
int mult(int);

int main(void){
    int a=5; // var locale
    changeMULTIPLIER(10); // 5*10
    printf("%d*%d = %d\n", a, MULTIPLIER, mult(a));
    changeMULTIPLIER(8); // 5*80
    printf("%d*%d = %d\n", a, MULTIPLIER, mult(a));
    return 0;
}   

int mult(int a){
    return a * MULTIPLIER; // uso in lettura della var globale
}

void changeMULTIPLIER(int n){
    MULTIPLIER = MULTIPLIER*n; // uso in scrittura della var globale
}