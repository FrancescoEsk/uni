#include <stdio.h>
#define N 3
/*
data una matrice m NxN trovare quanti elementi primi ci sono nella diagonale 
e quanti elementi non primi (nella diagonale) mettendo il risultato in una struttura

4
 5
  7
   9

p=2 e np=2
*/

typedef struct {
    int p; // quanti primi
    int np; // quanti non primi
} info;

int primo(int);

int main(void){
    int m[N][N];
    info in;
    in.p = 0;
    in.np = 0;
    // ottengo m
    for (int i=0; i<N; i++){
        for (int z=0; z<N; z++){
            printf("Inserisci il numero [%i][%i]: ", i, z);
            scanf("%i", &m[i][z]);

            if(i==z){
                if(primo(m[i][z]))
                    in.p++;
                else
                    in.np++;
            }
        }
    }
    printf("Numeri primi: %i\nNumeri non primi: %i\n", in.p, in.np);
    return 0;
}

int primo(int a){
    if (a<2)
        return 0;
    for(int i=2; i<=a/2; i++){
        if(a%i == 0)
            return 0;
    }
    return 1;
}