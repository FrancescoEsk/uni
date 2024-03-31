#include <stdio.h>
/*
Scrivere un programma che, chiesti all'utente due numeri interi positivi a e b 
comunica all'utente se si tratta di una coppia di numeri affiatati oppure no. 
Definiamo due numeri affiatati se sono diversi tra loro e la loro somma è pari 
al prodotto delle cifre che li compongono. Ad esempio (14, 34) e (63, 81) 
sono coppie di numeri affiatati perché
 14 + 34 = 1 x 4 x 3 x 4 = 48
 63 + 81 = 6 x 3 x 8 x 1 = 144
*/

int main(void){
    int a, b, prodotto=1;
    do {
        printf("Inserisci a: ");
        scanf("%i", &a);
        printf("Inserisci b: ");
        scanf("%i", &b);
    } while(a==0 || b==0);

    int x=a;
    while (x%10!=0){
        prodotto *= x%10; // moltiplico al prodotto le cifre di a
        x /= 10;
    }
    x=b;
    while (x%10!=0){
        prodotto *= x%10; // e poi di b
        x /= 10;
    }

    if (a!=b && a+b == prodotto) // controllo
        printf("I numeri %i e %i sono affiatati\n", a, b);
    else
        printf("I numeri %i e %i non sono affiatati\n", a, b);
    return 0;
}