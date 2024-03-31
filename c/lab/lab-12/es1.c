#include <stdio.h>
/*
Scrivere un programma C che dichiara e inizializza (con valori a piacere) un 
int, un float e un char. Quindi dichiara e inizializza un puntatore a 
ciascuna delle tre variabili. Il programma infine stampa l'indirizzo, il valore 
memorizzato e lo spazio occupato (in byte) di ciascuna delle sei variabili. 
Inoltre, per le variabili puntatore stampa anche il “valore puntato”.
*/

int main(void){
    int a;
    float b;
    char c;
    scanf("%d", &a);
    scanf("%f", &b);
    scanf(" %c", &c);
    int *aP = &a;
    float *bP = &b;
    char *cP = &c;
    printf("ind: %p, val: %d, byte: %lu\n", &a, a, sizeof(a));
    printf("ind: %p, val: %f, byte: %lu\n", &b, b, sizeof(b));
    printf("ind: %p, val: %c, byte: %lu\n", &c, c, sizeof(c));
    printf("ind: %p, val: %d, byte: %lu\n", aP, *aP, sizeof(aP));
    printf("ind: %p, val: %f, byte: %lu\n", bP, *bP, sizeof(bP));
    printf("ind: %p, val: %c, byte: %lu\n", cP, *cP, sizeof(cP));
    return 0;
}