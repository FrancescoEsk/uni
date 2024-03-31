#include <stdio.h>
#define N 6
#define M 2

/*
verificare se il secondo array è contenuto almeno una volta nel primo
*/

int main(void){
    int v[N], d[N], x=0, count=0;
    printf("Array 1: \n");
    for (int i=0; i<N; i++){
        do  scanf("%i", &v[i]);
        while(v[i] <= 0);
    }
    printf("Array 2: \n");
    for (int i=0; i<M; i++){
        do  scanf("%i", &d[i]); 
        while(d[i] <= 0);
    }

    for (int i=0; i<N && !count; i++){
        if (v[i] == d[x])   x++; // se il numero combacia avanzo nel secondo array
        else    x=0; // se non combacia ricomincio a leggere il secondo array
        
        if (x==M)   count=1; // se arrivo all'indice finale del secondo array significa che è contenuto
    }
    
    if (count)  printf("Il secondo array è contenuto almeno una volta nel primo\n"); // se count è ad 1 allora è contenuto
    else    printf("Il secondo array non è contenuto almento una volta nel primo\n");
    return 0;
}