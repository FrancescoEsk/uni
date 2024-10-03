#include <stdio.h>
#define M 6
#define N 4
#define P 5
/*
calcolare il prodotto matriciale di due matrici
a[6][4]
b[4][5]
Prodotto --> p[6][5]
*/

int main(void){
    int a[M][N], b[N][P], p[M][P];
    for (int i=0; i<M; i++){
        for (int z=0; z<P; z++){
            p[i][z] = 0;
            for (int k=0; k<N; k++) p[i][z] += a[i][k]*b[k][z];
        }
    }

    for(int i=0; i<M; i++){
        for(int z=0; z<P; z++) printf("%i ", p[i][z]);
        printf("\n");
    }
    
    return 0;
}