#include <stdio.h>
#include <stdlib.h>
#define N 2
#define M 3
/*
1 - dichiara una matrice matrix che ha dimensioni NxM (definite all'inizio)
2 - dichiara due vettori di int multR e multC (N e M)
3 - inizializza la matrice 
    righe pari --> numeri random PARI
    righe dispari --> numeri random DISPARI
    (numero random compreso tra 0 e 10 SEMPRE)
4 - implementare la moltiplicazione per righe e per colonne --> salvate in multR e multC
*/

int main(void){
    int multR[N], multC[M], m[N][M];
    int sum;
    srand(2); // inizializzazione random

    for(int i=0; i<N; i++){
        sum = 1;
        for (int z=0; z<M; z++){
            if (i%2 == 0)
                m[i][z] = (rand()%6 )*2; // se faccio %6 ottengo un numero tra 0 e 5, moltiplicato per due fa sicuro un pari
            else
                m[i][z] = ((rand()%6) *2) +1; // moltiplicato per 2 e aggiunto uno, sicuramente*2 --> pari, +1 --> dispari
            sum *= m[i][z];
            // printf("%i ", m[i][z]);
        }
        multR[i] = sum;
        printf("\nRiga %i --> %i\n", i+1, multR[i]);
    }

    for(int z=0; z<M; z++){
        sum = 1;
        for(int i=0; i<N; i++){
            sum += m[i][z];
        }
        multC[z] = sum;
        printf("Colonna %i --> %i\n", z+1, multC[z]);
    }

    return 0;
}