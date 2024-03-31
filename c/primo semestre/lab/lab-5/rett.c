#include <stdio.h>

/*
Scrivere un programma che ricevuto in ingresso due numeri interi 
positivi a e b (se così non è, li richiede), visualizza un rettangolo di 
dimensione a*b usando il carattere '*’
*/

int main(void){
    int a, b, x;
    do{
        printf("Inserisci a: ");
        scanf("%i", &a);
        printf("Inserisci b: ");
        scanf("%i", &b);
    } while(a<=0 || b<=0);

    while (a!=0){
        x=b;
        while (x!=0){
            printf("* ");
            x--;
        }
        printf("\n");
        a--;
    }
    
    return 0;
}