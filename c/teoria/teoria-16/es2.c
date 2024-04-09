#include <stdio.h>
/*
Scrivere un programma che inverta le cifre di un numero
intero n usando una apposita funzione ricorsiva

n = 4325
ris = 5234
*/

int inverti(int, int);

int main(void){
    int a;
    scanf("%d", &a);
    printf("%d\n", inverti(a, 0));
    return 0;
}

int inverti(int x, int part){
    if(x==0){
        return part;
    } else {
        return inverti(x/10, part*10 + x%10);
    }
}
