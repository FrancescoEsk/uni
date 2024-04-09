#include <stdio.h>
#define N 10
/*
funzione ricorsiva che calcola il massimo di un array di interi
con procedimento ricorsivo
*/

int max(int*, int*, int);

int main(void){
    int a[N];
    for(int i=0; i<N; i++)
        scanf("%d", &a[i]);
    printf("%d\n", max(a, &a[N], a[0]));
    return 0;
}

// passo indirizzo dell'array (punta ad indice 0), indirizzo della fine dell'array (&a[N]) e il massimo attuale
int max(int *a, int *dim, int m){
    if(a == dim) // se il puntatore arriva oltre l'array termina
        return m;
    else if(*a > m) // se l'elemento dell'array è maggiore di m, aggiorno il massimo
        return max(a+1, dim, *a); // aumento sempre l'indice dell'array di 1
    else // altrimenti mantengo lo stesso
        return max(a+1, dim, m); // aumento sempre l'indice dell'array di 1
}