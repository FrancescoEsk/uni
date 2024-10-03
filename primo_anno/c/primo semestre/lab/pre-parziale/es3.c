#include <stdio.h>
#define N 10
/*
scrivere un programma che acquisisce un array di 10 numeri interi
Il programma, terminata l'acquisizione, "muove" tutti i valore diversi da 0 
a sinistra dell'array e tutti gli zeri a destra.
al termine il programma visualizza l'array seguito dal numero di valori non nulli in esso presenti. 
*/

int main(void){
    int a[N], temp;
    for (int i=0; i<N; i++){
        printf("Inserisci [%i]: ", i);
        scanf("%i", &a[i]);
    }

    for (int l=0; l<N-1; l++){
        if (a[l]==0 && a[l+1] != 0){ // caso in cui ho 0 seguito da un numero intero
            for(int z=l; z<N-1; z++){ // shift dx partendo dallo 0 trovato
                temp = a[z+1]; 
                a[z+1] = a[z];
                a[z] = temp;
            }
            l=-1;
        }
    }

    for (int i=0; i<N; i++)
        printf("%i ", a[i]);
    printf("\n");
    return 0;
}