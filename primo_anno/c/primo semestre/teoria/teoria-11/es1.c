#include <stdio.h>
#define N 5
/*
dato un numero sicuramente maggiore di 0 verificare che tutte le sue cifre 
siano presenti in un array dato
*/

int check(int, int[N]);

int main(void){
    int a[N], n;

    do{
        printf("Inserisci n: ");
        scanf("%i", &n);
    } while(n<=0);

    for(int i=0; i<N; i++){
        printf("Inserisci il numero %i: ", i+1);
        scanf("%i", &a[i]);
    }

    if(check(n, a))
        printf("Condizione verificata\n");
    else
        printf("Condizione non verificata\n");

    return 0;
}
// verifica che le cifre del numero a siano tutte comprese nell'array dato (1)
int check(int a, int v[N]){ 
    int x, c;
    while (a>0){
        c=0;
        x = a%10;
        for(int i=0; i<N; i++)
            if(x == v[i])   c = 1;
        if (!c)
            return 0;
        a /= 10;
    }
    return 1;
}