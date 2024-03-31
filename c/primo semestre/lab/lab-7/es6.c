#include <stdio.h>
#define M 5
/*
Scrivere un programma C che chiede all’utente un numero intero n. Il
programma inizializza il contenuto della matrice seguendo il seguente
schema:
n n+1 n+2 n+3 n+4
n+1 n+1 n+2 n+3 n+4
n+2 n+2 n+2 n+3 n+4
n+3 n+3 n+3 n+3 n+4
n+4 n+4 n+4 n+4 n+4
Per esempio se n=5, il programma popolerà come segue:
5 6 7 8 9
6 6 7 8 9
7 7 7 8 9
8 8 8 8 9
9 9 9 9 9
*/

int main(void){
    int a[M][M];
    int n;

    printf("Inserisci n: ");
    scanf("%i", &n);

    for(int i=0; i<M; i++){
        for (int z=0; z<M; z++){
            if (z <= i) a[i][z] = n+i;
            if (z > i) a[i][z] = n+z;

        }
    }

    for(int i=0; i<M; i++){
        for (int z=0; z<M; z++){
            printf("%i ", a[i][z]);
        }
        printf("\n");
    }
    return 0;
}