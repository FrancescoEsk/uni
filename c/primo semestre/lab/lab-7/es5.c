#include <stdio.h>
#define M 3
/*
Scrivere un programma che chiede all’utente di inserire
una matrice di interi di dimensione 3X3.
 Il programma stampa a video la matrice stessa e poi il
valore 1 se la matrice contiene tutti gli interi a partire da 0
fino al numero di celle matrice -1, 0 in caso contrario.
 Ad esempio: con la matrice
1 0 2
3 4 6
5 7 8
il programma stamperà a video la matrice e quindi
il valore 1.
*/

int main(void){
    int a[M][M];
    int x = 0, check = 0, t;

    for(int i=0; i<M; i++){ // inserimento
        for (int z=0; z<M; z++){
            printf("inserisci: ");
            scanf("%i", &a[i][z]);
        }
    }

    for(int i=0; i<M; i++){ // stampa e check
        for (int z=0; z<M; z++){
            printf("%i ", a[i][z]);
            t=0;
            for (int k=0; k<M; k++){
                for (int j=0; j<M; j++){
                    if (a[k][j]== x){
                        t = 1;
                    }
                }
            }
            if(t==1) x++;
        }
        printf("\n");
    }

    if (x==M*M)   check = 1;
    printf("%i\n", check);
    return 0;
}