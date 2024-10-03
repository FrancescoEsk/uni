#include <stdio.h>
#define N 5

/*
Scrivere un programma che permette all’utente di inserire una matrice di valori
interi di dimensione NxN (con N pari a 5). Il programma deve poi calcolare e
stampare l’indice [espresso in numero ma indicante la colonna in linguaggio
naturale] della colonna in cui la massima differenza (in valore assoluto) ottenuta
tra due suoi elementi, sia massima. Nel caso ci sia più̀ di una colonna con
uguale differenza massima, stamperà l'indice della prima colonna trovata. Ad
esempio, se la matrice inserita fosse:

Il programma stamperà̀ l’indice 4(!): tale colonna ha come massima differenza
10 (diff. tra 20 e 10), ed è maggiore della differenza massima delle altre quattro
colonne, rispettivamente 9, 6, 8 e 7.
*/

int main(void){
    int a[N][N]/* = {
        {2, 5, 10, 15, 18},
        {11, 7, 7, 20, 15},
        {5, 5, 7, 11, 22},
        {6, 1, 3, 16, 19},
        {7, 1, 2, 10, 18}
    }*/;
    int diff, diffF=0, c, temp;
    for(int i=0; i<N; i++){ // inserimento
        for (int z=0; z<N; z++){
            printf("inserisci: ");
            scanf("%i", &a[i][z]);
        }
    }

    for(int z=0; z<N; z++){
        for (int i=0; i<N; i++){
            diff = 0;
            for (int k=i+1; k<N; k++){
                temp = a[i][z] - a[k][z];
                if (temp <0) temp = -temp; // valore assoluto
                if (temp > diff){
                    diff = temp;
                }
            }
            if (diff > diffF){ // se una colonna ha la stessa diff max di un'altra, non entra
                c = z+1; // salvo colonna in "naturale"
                diffF = diff;
            }
        }
    }

    printf("%i\n", c);
    return 0;
}