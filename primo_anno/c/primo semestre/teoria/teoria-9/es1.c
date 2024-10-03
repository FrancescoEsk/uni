#include <stdio.h>
/*
SOTTOPROGRAMMA (Funzione)

(a, b) = a! / b! * (a-b)!      coefficiente binomiale

programma che calcola il coefficiente binomiale di due numeri inseriti dall'utente.
*/

int input();
int fattoriale (int);

int main(void){
    int a, b, fatt1=1, fatt2=1, fatt3=1, binom;

    // richiedere input
    /*
    printf("Inserire un numero intero: ");
    scanf("%i", &a);
    printf("Inserire un numero intero: ");
    scanf("%i", &b);
    */
    a = input();
    b = input();

    // calcolare fattoriale
    /*
    for(int i=1; i<a; i++)
        fatt1 *= i;
    for(int i=1; i<b; i++)
        fatt2 *= i;
    for(int i=1; i<(a-b); i++)
        fatt3 *= i;
    */
    fatt1 = fattoriale(a);
    fatt2 = fattoriale(b);
    fatt3 = fattoriale(b-a);

    printf("Il coefficiente binomiale di (%i,  %i) e': %i", a, b, fatt1 / (fatt2 * fatt3));
    return 0;
}

int input(){
    int x;
    do{
        printf("Inserire un numero intero: ");
        scanf("%i", &x);
    } while (x<=0);

    return x;
}

int fattoriale (int x){
    int fatt;
    for(int i=1; i<x; i++)
        fatt *= i;

    return fatt;
}