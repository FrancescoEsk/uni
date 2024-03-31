#include <stdio.h>
/*
dato un numero dire se è primo
*/

int main(void){
    int n, t=0;
    printf("Inserisci il numero: ");
    scanf("%i", &n);
    for (int i=2; i<=(n/2);i++)
        if(n%i==0){
            t = 1;
            break;
        }
        

    if(t==0)
        printf("Il numero e' primo\n");
    else
        printf("Il numero non e' primo\n");
    return 0;
}