#include <stdio.h>
/*
Scrivere un programma c che prende in ingresso
due numeri interi, calcola il loro valore assoluto, 
determina qual è il più grande e lo stampa.
*/

int modulo(int);

int main(void){
    int a, b;
    printf("Inserisci il primo numero: ");
    scanf("%i", &a);
    printf("Inserisci il secondo numero: ");
    scanf("%i", &b);

    a = modulo(a);
    b = modulo(b);

    if(a>b)
        printf("Il numero piu' grande e' il primo\n");
    else if (a<b)
        printf("Il numero piu' grande e' il secondo\n");
    else
        printf("Non c'e' un numero piu' grande dell'altro\n");
    return 0;
}

int modulo(int x){
    if(x>=0)
        return x;
    else
        return -x;
}