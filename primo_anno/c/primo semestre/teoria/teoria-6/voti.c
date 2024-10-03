#include <stdio.h>
#define N 10
#define D 6
/*
Voti compresi tra 0 e 10 compreso
Acquisire N voti
contare quanti 0, quanti 1,...., quanti 10 ci sono in a[]
*/

int main(void){
    int a[N];
    int count[D] = {0};  // azzero tutte le posizioni dell'array

    for (int i=0;i<N; i++){
        do{
            printf("Inserisci il voto: ");
            scanf("%i", &a[i]);
        } while(a[i]<5 || a[i]>10);
    }
    
    for (int i=0; i<N; i++){
        count[a[i]-5]++; // se in a[0] = 5, aumento la cella count[5] di 1
    }

    printf("Conta dei numeri inseriti:\n");
    for (int i=0; i<D; i++)
        printf("Conta di %i: %i\n", i+5, count[i]);

    return 0;
}