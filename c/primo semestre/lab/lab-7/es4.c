#include <stdio.h>
#define M 3

/*
 Scrivere un programma che chiede all’utente di inserire da
tastiera una matrice 3X3 con soli valori maggiori o uguali a
zero.
 Il programma, dopo aver stampato la matrice a video,
verifica se la matrice è pari o meno e stampa un opportuno
messaggio a video.
 Una matrice si dice pari se è composta di soli valori
pari.
 Ad esempio, se l’utente inserisce la seguente matrice
 4 0 2
4 4 6
6 4 8
L’output sarà del tipo: Matrice pari? 1
*/

int main(void){
    int a[M][M];
    int check=1;

    for(int i=0; i<M; i++){ // inserimento
        for (int z=0; z<M; z++){
            do{
                printf("inserisci: ");
                scanf("%i", &a[i][z]);
            } while (a[i][z] < 0);
        }
    }

    for(int i=0; i<M; i++){ // stampa e check pari
        for (int z=0; z<M; z++){
            printf("%i ", a[i][z]);

            if (a[i][z]%2 != 0) check=0;
        }
        printf("\n");
    }

    printf("Matrice pari? %i\n", check);
    return 0;
}