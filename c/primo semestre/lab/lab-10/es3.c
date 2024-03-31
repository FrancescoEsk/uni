#include <stdio.h>
#define R 10
#define C 7

/*
Data una matrice RXC di interi (con R=10 e C=7), un suo elemento è definito
picco se è sia il massimo (strettamente maggiore di tutti gli altri) elemento
della sua colonna, sia il massimo della sua riga. 
Scrivere un programma C che:

1) conta e stampa a video il numero di picchi contenuti in una matrice

2) inizializza un array di interi con gli indici delle righe della matrice in cui si
trovano picchi.

Ad esempio, data la seguente matrice il programma stampa 3 (i picchi sono
evidenziati in grassetto) e l’array {0,4,7}.
*/

int main(void){
    int m[R][C] = {
        {1, 2, 9, 1},
        {8, 2, 1, 2},
        {1, 2, 2, 1},
        {1, 1, 1, 5}
    };
    int a[C];
    int x, checkR, checkC, count=0, n=0;

    for (int i=0; i<R; i++){
        for (int z=0; z<C; z++){
            x = m[i][z];
            checkR=1;
            checkC=1;

            for (int k = 0; k<R; k++){ // check riga
                if (k != z && x<=m[i][k])  checkR=0;
            }

            for (int k = 0; k<C; k++){ // check colonna
                if (k != i && x<=m[k][z])  checkC=0;
            }

            if (checkR == 1 && checkC == 1){
                count++; 
                a[n] = i; // inserisco nell'array degli indici
                n++;
            }
        }
    }

    printf("Numero di picchi della matrice: %i\nIndici contenenti picchi: ", count);
    
    for (int i=0; i<n; i++)
        printf("%i ", a[i]);
    printf("\n");
    return 0;
}
