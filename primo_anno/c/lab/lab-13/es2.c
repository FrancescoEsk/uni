#include <stdio.h>
#define N 3
/*
Scrivere due sottoprogrammi maxr() e maxc() che prendono in ingresso 
(o definiscono nel codice) una matrice 3X3 di interi e restituiscono 
rispettivamente al chiamante l’indice della riga/colonna in cui la somma 
di tutti gli elementi è massima.

Scrivere la funzione main() per testare le funzioni create.
*/

int maxr(int[][N], int);
int maxc(int[][N], int);

int main(void){
    int a[N][N];
    for(int i=0; i<N; i++)
        for(int z=0; z<N; z++)
            scanf("%d", &a[i][z]);
    
    printf("maxc: %d, maxr: %d\n", maxc(a, N), maxr(a, N));
    return 0;
}

int maxr(int m[][N], int dim){
    int sum, max, r;
    for(int i=0; i<dim; i++){
        sum = 0;
        for(int z=0; z<N; z++){
            sum += m[i][z];
        }
        if (max<sum || i==0){
            r = i;
            max = sum;
        }
    }
    return r;
}

int maxc(int m[][N], int dim){
    int sum, max, r=0;
    for(int z=0; z<N; z++){
        sum = 0;
        for(int i=0; i<dim; i++){
            sum += m[i][z];
        }
        if (max<sum || z==0){
            max = sum;
            r = z;
        }
    }
    return r;
}