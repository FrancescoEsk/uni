#include <stdio.h>
#include <stdlib.h>
/*
come dichiarare una matrice di dimensione dinamica, in modo da essere chiamata tramite
m[i][j]
*/

int main(void){
    int **p;
    int r, c;
    printf("Quante righe e colonne? ");
    scanf("%d %d", &r, &c); // spazio in memoria: r * c * sizeof(int)

    // allocare la memoria nello heap
    p = (int**) malloc(r*sizeof(int*)); // ogni elemento è un puntatore all'area di mem che contiene la riga

    for(int i=0; i<r; i++){ // allocamento righe
        p[i] = (int*) malloc(c*sizeof(int)); // alloco gli array delle righe
    }

    for(int i=0; i<r; i++){ // allocamento valori
        for(int j=0; j<c; j++){
            printf("Elemento riga %d, colonna %d: ", i, j);
            scanf("%d", &p[i][j]);
        }
    }

    for(int i=0; i<r; i++){ // stampa
        for(int j=0; j<c; j++){
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }

    free(p);
    return 0;
}