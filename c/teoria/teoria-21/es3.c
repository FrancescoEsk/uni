#include <stdio.h>
#include <stdlib.h>
#define N 3
#define M 3
/*
implementare funzione 'conta' che riceve due parametri:
- matrice mat di int, dimensione N*M (note a priori)
- array b di cui ci viene data la dimensione (come parametro della funzione)

verificare il numero di colonne in cui l'array b compare nella matrice in posizioni contigue

*/

int conta(int[N][M], int*, int);

int main(void){
    int mat[N][M];

    for(int i=0; i<N; i++){
        for(int z=0; z<M; z++){
            scanf("%d", &mat[i][z]);
        }
    }

    int b[3] = {1, 4, 7};

    printf("Risultato: %d\n", conta(mat, b, 3));

    return 0;
}

int conta(int mat[N][M], int *b, int dim){
    if(dim>M)
        return 0;
    int count=0, check;
    int *tmp;
    for(int z=0; z<N; z++){
        tmp = b;
        check = 0;
        for(int i=0; i<M && check != dim; i++){
            if(*tmp == mat[i][z]){
                tmp++;
                check++;
            } else {
                tmp = b;
                check = 0;
            }
            if(check == dim){
                count++;
            }
        }
    }
    return count;
}