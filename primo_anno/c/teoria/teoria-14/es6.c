#include <stdio.h>
#define N 10
/*
scrivere un sottoprog c che riceve come parametri un array di interi e la sua dimensione,
e sostituisce ciascun valore negativo presente nell'array con il suo valore assoluto

usare il sottoprogramma nel main
*/

void ass(int[], int);

int main(void){
    int a[N];
    for(int i=0; i<N; i++)
        scanf("%d", &a[i]);

    ass(a, N);

    for(int i=0; i<N; i++)
        printf("%d ", a[i]);
    printf("\n");
    
    return 0;
}

void ass(int v[], int d){
    for(int i=0; i<d; i++){
        if(v[i] < 0)
            v[i] = -v[i];
    }
}