#include <stdio.h>
#define N 10
/*
Tema d'esame

Acquisire 10 numeri interi (array) e calcolare la coppia di numeri la cui somma è massima
*/

int main(void){
    int a[N], max=0, pos1, pos2;

    for (int i=0; i<N; i++)
        scanf("%i",&a[i]);
    
    for (int i=1; i<N; i++){
        if (!max || max< a[i-1]+a[i]){
            max = a[i-1] + a[i];
            pos1 = i-1;
            pos2 = i;
        }
    }

    printf("La coppia di numeri %i e %i sono quelli con la somma più alta dell'array: %i\n", a[pos1], a[pos2], max);
    return 0;
}