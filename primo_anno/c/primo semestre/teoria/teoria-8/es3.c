#include <stdio.h>
#define N 4
#define M 8
/*
matrice 4*8

5 9 2 4 1 7 2 4
3 5 6 2 5 6 1 2
1 3 4 7 8 8 3 0
1 3 5 6 7 8 2 1

da acquisire

si dice dominante un elemento della matrice 
se è strettamente maggiore di tutti gli leementi della sottomatrice che si trova in basso a dx
rispetto all'elemento

stampare il numero di elementi dominanti
*/

int main(void){
    int a[N][M], x, check=0;
    for (int i=0; i<N; i++){
        for (int z=0; z<M; z++){
            printf("Inserisci il valore [%i][%i]: ", i, z);
            scanf("%i", &a[i][z]);
        }
    }

    for (int i=0; i<N-1; i++){ // salto l'ultima colonna N-1 e riga M-1
        for (int z=0; z<M-1; z++){
            x=0;
            for (int j=i+1; j<N && !x; j++){ // leggo la sottomatrice in basso a dx del numero 
                for (int k=z+1; k<M && !x; k++){
                    if (a[i][z] <= a[j][k]) // se il numero in questione non è strettamente maggiore, non è dominante
                        x=1;
                }
            }
            if (x==0)   check++; // se è strettamente maggiore di tutti gli elementi lo aggiungo al counter dei dominanti
        }
    }
    printf("La matrice inserita contiene %i dominanti\n", check);
    return 0;
}