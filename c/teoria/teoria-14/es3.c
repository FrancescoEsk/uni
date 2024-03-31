#include <stdio.h>
#define N 10
/*
scrivere un sottoprogramma che riceve come parametri un array di interi e la sua dimensione

il sottoprogramma calcola la somma dei valori contenuti nell'array e ritorna il risultato

scrivere un programma che richiede all'utente 10 valori , invoca la funzione e stampa il risultato
*/

int sum(int[], int);
int sum2(int[], int);

int main(void){
    int a[N];
    for(int i=0; i<N; i++)
        scanf("%d", &a[i]);

    printf("sum1: %d, sum2: %d\n", sum(a, N), sum2(a, N));
    return 0;
}

int sum(int v[], int dim){
    int s=0;
    for(int i=0; i<dim; i++)
        s += v[i];
    return s;
}


int sum2(int *v, int dim){
    int s=0;
    for(int i=0; i<dim; i++)
        s += *(v+i);
    return s;
}
