#include <stdio.h>
#define N 4
#define M 3
/*
dati in input da tastiera una matrice nxm ed un numero L 
sicuramente maggiore di 0 e minore di N, stampi:
- OK se nella matrice esiste almeno una sequenza verticale di lunghezza
    almeno L di elementi che crescono o decrescono linearmente (cioè in cui
    la differenza tra due numeri successivi è costante)
- KO altrimenti
*/

void check(int [N][M], int);
int diff(int, int);

int main(void){
    int m[N][M], L;
    for(int i=0; i<N;i++){
        for (int z=0; z<M;z++){
            printf("Inserisci [%i][%i]: ", i, z);
            scanf("%i", &m[i][z]);
        }
    }
    do{
        printf("Inserisci L: ");
        scanf("%i", &L);
    } while(L<0 && L>=N);
    check(m, L);
    return 0;
}

int diff(int a, int b){
    int x = a - b;
    if(x<0)
        return -x;
    else return x;
}

void check(int m[N][M], int L){
    int c, x, temp, k=0;
    for(int z=0; z<M && !k;z++){
        x=0;
        c=0;
        for (int i=0; i<N-1 && !k;i++){
            if (x==0) // se x vale 0 (primo giro), inserisco in x la diff tra i due numeri
                x = diff(m[i][z], m[i+1][z]);

            temp = diff(m[i][z], m[i+1][z]);
            if (temp==x) // se la differenza combacia con il valore salvato, aumento il count
                c++;
            else{
                x = temp; // reset x
                c = 1; // starto il counter ad 1
            } // altrimenti cambio il valore di x con la nuova differenza e aumento il count

            if (c==L-1) // se arrivo ad avere il count pari ad L ho raggiunto l'obbiettivo
                k=1;
        }
    }
    if (k)
        printf("OK\n");
    else
        printf("KO\n"); // se non riesco, stampo il falso;
}