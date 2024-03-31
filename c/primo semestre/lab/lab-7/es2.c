#include <stdio.h>
#define M 3

/*
Scrivere un programma che data una matrice int A[M]
[M] esegua la sommatoria di tutti gli elementi che si
trovano sopra la diagonale principale
*/

int main(void){
    int A[M][M];
    int somma = 0;

    for(int i=0; i<M; i++){
        for (int z=0; z<M; z++){
            printf("inserisci: ");
            scanf("%i", &A[i][z]);
        }
    }

    for(int i=0; i<M; i++){
        for (int z=0; z<M; z++){
            if (z>i){
                somma += A[i][z];
            }
        }
    }

    printf("Somma: %i\n", somma);
    return 0;
}