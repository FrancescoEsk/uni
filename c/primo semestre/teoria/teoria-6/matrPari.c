#include <stdio.h>
#define D 3

/*
Stampare il numero di elementi pari per riga di una matrice m
*/

int main(void){
    int m[3][3] = {{1,2,3},{4,5,6},{7,8,9}}, par=0;

    for (int i=0; i<D; i++){
        for(int z=0;z<D;z++){
            if(m[i][z]%2 == 0)
                par++;
        }
        printf("Quantita' di pari nella riga %i: %i", i, par);
        par=0;
    }
    return 0;
}