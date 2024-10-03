#include <stdio.h>
/*
Scrivere una funzione ricorsiva che calcola la somma di tutti i naturali compresi tra 0 e x

x viene letto da tastiera nel main, deve essere positivo, e viene passato come parametro alla funzione.
*/

int somma(int);

int main(void){
    int x;
    do{
        scanf("%d", &x);
    } while(x<0);
    printf("Somma ricorsiva da 0 a %d: %d\n", x, somma(x));
    return 0;
}

int somma(int x){
    if(x==0)
        return 0;
    else
        return x + somma(x-1);
}