#include <stdio.h>
#define N 10
/*
Scrivere sottoprogramma con il seguente prototipo:
int conta(int a[], int dim, int *primi)
che preso come parametro un array di interi e la sua dimensione (al massimo di 10 interi), 
conta quanti numeri dispari e quanti numeri primi sono presenti nell’array e restituisce 
entrambi i valori al chiamante.
Il main chiede in ingresso all’utente un array di massimo 10 interi (-1 per terminare), 
richiamando il sottoprogramma conta stampa i due valori numerici ottenuti.
*/

int conta(int[], int, int*);
int primo(int);

int main(void){
    int a[N], primi = 0, x, check=1, i;
    for(i=0; i<N && check != 0; i++){
        scanf("%d", &a[i]);
        if (a[i] == -1)
            check=0;
    }
    
    x = conta(a, i, &primi);
    printf("dispari: %d, pari: %d\n", x, primi);

    return 0;
}

int primo(int x){
    for(int i=1; i<=x/2; i++){
        if(x%i == 0)
            return 1;
    }
    return 0;
}

int conta(int a[], int dim, int *primi){
    int dispari = 0;
    for(int i=0; i<dim; i++){
        if (a[i]%2==1)
            dispari++;
        if(primo(a[i])==1)
            *primi = *primi +1;
    }
    return dispari;
}