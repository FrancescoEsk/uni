#include <stdio.h>
#define N 3

/*
Esempio utilizzo matrici
*/

int main(void){
    int a[3][3]; // quadrata
    int b[5][3]; // rettangolare
    int m[N][N] = {{1,2,3},{4,5,6},{7,8,9}};
    
    /*
    for (int i=0;i<N;i++){ // popolamento
        for (int j=0; j<N; j++){
            printf("Inserisci il numero: ");
            scanf("%i", &m[i][j]);
        }
    }*/

    for (int i=0;i<N;i++){ // stampa
        for (int j=0; j<N; j++){
            printf("%3i ", m[i][j]);
        }
        printf("\n");
    }
    printf("\nDiagonale primaria\n");

    for (int i=0;i<N;i++){ // stampa diagonale principale
        printf("%3i ", m[i][i]);
    }
    printf("\nDiagonale secondaria\n");

    for (int i=0,z=N-1;i<N && z>=0;i++,z--){ // stampa diagonale secondaria
        printf("%3i ", m[i][z]);
    }
    printf("\n\n");

    return 0;
}