#include <stdio.h>
#define N 3
/*
data un matrice NxN
- leggere matrice m1 di int
- creare matrie m2 di float (NxN)
- m2[i][z] --> media degli elementi sul bordo / intorno a m1[i][z], incluso m1[i][z]

1 0 0
0 1 0
0 0 1
*/

int main(void){
    int m1[N][N];
    float m2[N][N], s, c;
    // ottengo m1
    for (int i=0; i<N; i++){
        for (int z=0; z<N; z++){
            printf("Inserisci il numero [%i][%i]: ", i, z);
            scanf("%i", &m1[i][z]);
        }
    }
    // calcolo m2
    for (int i=0; i<N; i++){
        for (int z=0; z<N; z++){
            s = 0;
            c = 0;
            for (int j=i-1; j<=i+1; j++){ // scorro gli indici aggiuntivi attorno ad i e k
                for (int l=z-1; l<=z+1; l++){
                    if (j>=0 && j<N && l>=0 && l<N){ // se gli indici sono compresi nel campo della matrice sommo e conto
                        s += m1[j][l];
                        c++;
                    }
                }
            }
            m2[i][z] = s/c; // calcolo media e inserisco in m2
        }
    }
    // stampa m2
    for (int i=0; i<N; i++){
        for (int z=0; z<N; z++){
            printf("%.2f ", m2[i][z]);
        }
        printf("\n");
    }
    return 0;
}