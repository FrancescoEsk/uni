#include <stdio.h>
#define N 15
/*
Scrivere un programma C che memorizza in un array i 
primi 15 numeri di Fibonacci e li stampa a video
*/

int main(void){
    int a[N];
    for(int i=0; i<N; i++){
        if (i<2)  a[i] = i;
        else{
            a[i] = a[i-2] + a[i-1];
        }
    }

    for(int i=0; i<N; i++)	printf("%i ", a[i]);
    printf("\n");
    
    return 0;
}