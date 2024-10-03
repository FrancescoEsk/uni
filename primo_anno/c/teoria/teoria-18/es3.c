#include <stdio.h>
#define N 3
/*
scrivere un programma che inizializza e stampa il contenuto di una matrice
definita tramite una variabile globale
*/

int M[N][N]; // var globale (vale tutti 0)

void inserisci();
void stampa();

int main(void){
    inserisci();
    stampa();
    return 0;
}

void inserisci(){
    int x;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &x);
            M[i][j] = x;
        }
    }
}

void stampa(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}