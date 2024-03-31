#include <stdio.h>
/*
dato un numero intero positivo n 
- calcolare i numeri interi che sono divisori di n
- dire se n è primo
*/

int main(void){
    int n, check=0;
    do{
        printf("Inserisci il numero: ");
        scanf("%i", &n);
    } while(n<=0); // check numero maggiore di 0

    for (int i=2; i<=(n/2); i++){
        if (n%i==0){
            check++;
        }
    }
    if (check==0)   printf("Il numero inserito è primo\n");
    else    printf("Numero di divisori di %i: %i\n", n, check);
    return 0;
}