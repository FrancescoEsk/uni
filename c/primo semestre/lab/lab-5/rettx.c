#include <stdio.h>

/*
Scrivere un programma che ricevuto in ingresso due numeri interi 
positivi a e b (se così non è, li richiede), visualizza un rettangolo di 
dimensione a*b usando il carattere ‘*’ sui bordi e il carattere ‘X’ 
all’interno
*/

int main(void){
    int a, b, x, z;
    do{
        printf("Inserisci a: ");
        scanf("%i", &a);
        printf("Inserisci b: ");
        scanf("%i", &b);
    } while(a<=0 || b<=0);

    z = a;

    while (a!=0){
        x=b;
        while (x!=0){
            if (x==b || x==1 || a==z || a==1)
                printf("* ");
            else
                printf("X ");
            x--;
        }
        printf("\n");
        a--;
    }
    
    return 0;
}