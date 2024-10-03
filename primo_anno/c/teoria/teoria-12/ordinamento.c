#include <stdio.h>
#define N 10
/*
ordinare una sequenza di elementi (array)
molti algoritmi equivalenti
differiscono per
--> quanto sono intuitivi
--> quanto sono efficienti

NAIVE SORT  |   semplice, poco efficiente
BUBBLE SORT |   medio
INSERT SORT
MERGE SORT
QUICK SORT  |   più veloce ma più complicato

minor numero di confronti, migliore è l'algoritmo
*/

int main(void){
    // NAIVE SORT
    return 0;
}

void naivesort(int a[N]){
    int p, temp, x=N;
    while(x>1){
        p = 0; // posizione del massimo
        for(int i=1; i<x; i++){
            if (a[i]>a[p]){
                p = i;
            } 
        }
        // switch tra massimo e l'ultima posizione da scambiare
        temp = a[x-1];
        a[x-1] = a[p];
        a[p] = temp;
        x--; // riduco il campo di check
    }
    /*
    while (array non ord){
        trovare posizione p del massimo

        scambiare v[n-1] con v[p]

        restringere attenzione sulle prime n-1 posizioni
        n' = n-1
    }
    */
}

void bubblesort(int a[N]){
    int dim=N, ord=0, temp;
    while(dim>1 && ord==0){
        ord = 1;

        for(int x=1; x<dim; x++){
            if(a[x-1]>a[x]){ // se non è già ordinato, scambio
                temp = a[x];
                a[x] = a[x-1];
                a[x-1] = temp;
                ord = 0; // segno che l'array non era ancora ordinato
            }
        }
        
        dim--; // diminuisco la dimensione da confrontare
    }
}