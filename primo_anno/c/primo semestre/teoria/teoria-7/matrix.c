#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 4
#define m 3
/*
dichiarare una matrice di dimensione n * m di interi
dichiarare 2 vettori sumR e sumC
inizializzare la matrice in modo che:
    righe pari abbiano numeri random pari tra 0 e 10
    righe dispari abbiano numeri random dispari tra 1 e 9
calcolare la somma per righe e colonne (sumR e sumC)
stampare matrix, sumR e sumC
*/

int main(void){
    int matrix[n][m];
    int sumR[n], sumC[m];
    // rand() ritorna un numero random intero tra 0 e MAX INT
    for(int i=0; i<n; i++){
        for(int z=0; z<m; z++){
            if (i%2 == 0){
                matrix[i][z] = rand()%5 * 2; // -- per avere solo rand pari
            } else {
                matrix[i][z] = 1 + rand()%5 * 2; // -- per avere solo rand dispari
            }
            // FORMULA GENERALE PER GENERARE RANDOM TRA INTERVALLI --> MIN + rand()%(MAX-MIN + 1)
        }
    }
    for(int i=0; i<n; i++){
        sumR[i] = 0;
        for(int z=0; z<m; z++){
            sumR[i] += matrix[i][z];
        }
    }

    for(int z=0; z<m; z++){
        sumC[z] = 0;
        for(int i=0; i<n; i++){
            sumC[z] += matrix[i][z];
        }
    }

    for(int i=0; i<n; i++){
        for(int z=0; z<m; z++) printf("%i ", matrix[i][z]);
        printf("\n");
    }
    return 0;
}