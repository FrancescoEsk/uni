#include <stdio.h>
/*
Si definisce triangolare un numero costituito dalla somma dei primi N numeri 
interi positivi per un certo N. Esempio: dato N=4, il numero triangolare Q è 
10 (Q=1+2+3+4). Scrivere un programma che riceva dall’utente un numero 
intero positivo e stampi a video se è o meno triangolare (ossia se può essere 
scritto come somma dei primi N interi consecutivi).
*/

int main(void){
    int n, q=0, t=0;
    printf("Inserisci N: ");
    scanf("%i", &n);

    for(int i=0; i<n; i++){
        q += i;
        if (n==q)
            t = 1;
    }
    
    if ( t == 1)
        printf("Il numero inserito è triangolare\n");
    else
        printf("Il numero inserito non è triangolare\n");
    return 0;
}