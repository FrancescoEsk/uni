#include <stdio.h>
#define N 3
/*
matrice 5*5

sostituire gli elementi attorno a [k][j] con 0

0 0 0
0 x 0
0 0 0
*/

int main(void){
    int m[N][N];
    int k, j;
    for(int i=0; i<N; i++){
        for (int z=0; z<N; z++){
            printf("Inserisci il numero [%i][%i]: ", i, z);
            scanf("%i", &m[i][z]);
        }
    }
    printf("Inserisci k e j: ");
    scanf("%i %i", &k, &j);

    for(int i=0; i<N; i++){
        for (int z=0; z<N; z++){
            if (i==k-1 || i==k+1){
                if(z>=j-1 && z <=j+1 )
                    m[i][z] = 0;
            }
            if (i==k && (z==j-1 || z==j+1))
                m[i][z] = 0;
        }
    }

    for(int i=0; i<N; i++){
        for (int z=0; z<N; z++){
            printf("%i ", m[i][z]);
        }
        printf("\n");
    }
    return 0;
}