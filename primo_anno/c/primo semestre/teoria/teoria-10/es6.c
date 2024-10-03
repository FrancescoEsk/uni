#include <stdio.h>
#define S 3
/*
Legge una matrice int sxs e salva in un array di struct 
per ogni riga quanti elementi pari, dispari
*/

typedef struct {
    int index;
    int p;
    int d;
} el;

int main(void){
    int m[S][S];
    int countD, countP;
    el c[S];
    for(int i=0; i<S; i++){
        countP=0;
        countD=0;
        for(int z=0; z<S; z++){
            printf("Inserisci il valore [%i][%i]: ", i, z);
            scanf("%i", &m[i][z]);
            if (m[i][z]%2 == 0)
                countP++;
            else
                countD++;
        }
        c[i].index = i;
        c[i].p = countP;
        c[i].d = countD;
    }
    printf("\nElementi pari e dispari suddivisi per riga\n");
    for(int i=0; i<S; i++)
        printf("index: %i, pari: %i, dispari: %i\n", c[i].index, c[i].p, c[i].d);
    return 0;
}