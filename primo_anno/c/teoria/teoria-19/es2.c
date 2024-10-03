#include <stdio.h>
#include <stdlib.h>
/*
matrice in mem dinamica

Per selezionare gli indici == a[i*c + j] 
i - indice riga variato dal for
c - colonne tot
j = indice colonna variato dal for

*/

int main(void){
    int r, c; // # righe, # colonne 
    int *p;
    printf("Quante righe e colonne? ");
    scanf("%d %d", &r, &c); // spazio in memoria: r * c * sizeof(int)

    p = (int*) malloc(r*c*sizeof(int)); // puntatore al primo elemento della matrice
    
    for(int i=0; i<r; i++){ // allocamento
        for(int j=0; j<c; j++){
            printf("Elemento riga %d, colonna %d: ", i, j);
            scanf("%d", &p[i*c + j]);
        }
    }

    for(int i=0; i<r; i++){ // stampa
        for(int j=0; j<c; j++){
            printf("%d ", p[i*c + j]);
        }
        printf("\n");
    }

    free(p);
    return 0;
}