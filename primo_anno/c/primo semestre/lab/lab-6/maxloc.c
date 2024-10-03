#include <stdio.h>
#define N 10
/*
Scrivere un programma che dato un array di interi (lungo 
10) con i valori inseriti da tastiera determina quanti 
massimi locali ci sono nell’array stampando il risultato
*/

int main(void){
    int a[N];

    for(int i=0; i<N; i++){
        printf("Inserisci l'elemento numero %i: ", i);
        scanf("%i", &a[i]);
    }

    for(int i=0; i<N; i++){
        if (i==0){
            if (a[i]>a[i+1])    printf("%i in posizione %i e' un massimo locale nell'array\n", a[i], i);
        }
        else if (i==9){
            if (a[i]>a[i-1])    printf("%i in posizione %i e' un massimo locale nell'array\n", a[i], i);
        }         
        else if (a[i]>a[i-1] && a[i]<a[i+1]){
            printf("%i in posizione %i e' un massimo locale nell'array\n", a[i], i);
        }
    }
    return 0;
}