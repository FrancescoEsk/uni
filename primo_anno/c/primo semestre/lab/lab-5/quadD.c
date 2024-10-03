#include <stdio.h>

/*
Scrivere un programma che ricevuto in ingresso un numeri interi 
positivi a (se così non è, lo richiede), visualizza un quadrato di lato a 
usando il carattere ‘X’ sulla diagonale principale e il carattere ’*’ 
altrove
*/

int main(void){
    int a, x, z, count=0, temp;
    do{
        printf("Inserisci a: ");
        scanf("%i", &a);
    } while(a<=0);
    z = a;
    while (a!= 0){
        x = z;
        temp=0;
        while (x!=0){
            if (count == temp)
                printf("X ");
            else
                printf("* ");
            temp++;
            x--;
        }
        printf("\n");
        count++;
        a--;
    }
    return 0;
}