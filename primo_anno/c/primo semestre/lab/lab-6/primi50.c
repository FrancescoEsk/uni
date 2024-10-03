#include <stdio.h>
#define N 15
/*
Scrivere un programma C che memorizza in un array di 
lunghezza 15 tutti i numeri primi minori di 50 e 
successivamente li stampa a video
*/

int main(void){
    int a[N];
    int c = 0;
    for(int i=2; i<50; i++){
        int check=1;
        for (int z=2; z<=i/2; z++)
            if (i%z == 0) check=0;
        if (check==1){
            a[c] = i; c++; printf("%i ", i);
        }
    }
    return 0;
}