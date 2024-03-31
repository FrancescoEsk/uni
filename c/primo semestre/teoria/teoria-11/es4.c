#include <stdio.h>
#define N 3
/*
matrice m NxN 
si ritorna una struttura 
*/

typedef struct{
    int c; // indice matrice
    int max; // massimo elemento della colonna
    int t; // quanti elementi uguali al massimo
} info[N];

int main(void){
    int m[N][N], max;
    info in;
    // ottengo m
    for (int i=0; i<N; i++){
        for (int z=0; z<N; z++){
            printf("Inserisci il numero [%i][%i]: ", i, z);
            scanf("%i", &m[i][z]);
        }
    }

    for (int z=0; z<N; z++){
        in[z].c = z;
        in[z].t = 0;
        in[z].max = m[0][z];
        for (int i=0; i<N; i++){
            if (in[z].max<m[i][z]){
                in[z].max = m[i][z];
            }
        }
        for (int i=0; i<N; i++){
            if (in[z].max == m[i][z]){
                in[z].t++;
            }
        }
    }

    for(int i=0; i<N; i++)
        printf("Indice: %i, Max: %i, Count: %i\n", in[i].c, in[i].max, in[i].t);
    
    return 0;
}