#include <stdio.h>
/*
Un numero è strettamente monotono crescente se le cifre che lo costituiscono sono ordinate
in modo strettamente crescente da destra verso sinistra
es. 9520
321
6501 NON E' strettamente crescente monotono
Stampa quindi se è strettamente monotono crescente oppure no.
*/

int main(void){
    int n, x, check=1;
    do{
        printf("Inserisci il numero: ");
        scanf("%i", &n);
    } while(n<=0); // check numero maggiore di 0
    while (n>1){
        if (!x)   x = n%10; // se x non vale ancora nulla
        else if (n%10<x) x = n%10; // se la cifra è minore della precedente continuo
        else check=0; // se la cifra è maggiore o uguale della precedente, non e' strettamente monotono crescente
        n /= 10;
    }
    if (check==1)   printf("Il numero inserito e' strettamente monotono crescente\n");
    else    printf("Il numero inserito non e' strettamente monotono crescente\n");
    return 0;
}