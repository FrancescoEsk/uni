#include <stdio.h>

/*
Scrivere un sottoprogramma che ricevuto in ingresso un
intero positivo conta e restituisce al chiamante il numero di
cifre che compongono il numero in ingresso e ne sono divisori.
*/
int divisori(int);

int main(void){
    int n;
    do{
        printf("Inserisci n: ");
        scanf("%i", &n);
    } while(n<=0);
    
    printf("%i\n", divisori(n));
    return 0;
}

int divisori (int x){
    int temp;
    int save = x;
    int count=0;

    while(x>0){
        temp = x%10;
        if (save % temp == 0)  count++;
        x /= 10;
    }
    return count;
}