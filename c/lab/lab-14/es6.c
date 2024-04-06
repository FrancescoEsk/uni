#include <stdio.h>
/*
Scrivere una funzione ricorsiva
 int cifra(int num, int k)
che ritorna la k-esima cifra di num partendo da destra.
Ad esempio cifra(3879, 2) restituisce 7.
Scrivere la funzione main() per testare la funzione realizzata.
*/

void leggi (int*);
int cifra(int, int);

int main(void){
    int x, k;
    leggi(&x);
    leggi(&k);
    printf("%d\n", cifra(x, k));
    return 0;
}

int cifra(int num, int k){
    if(k==1)
        return num%10;
    else
        return cifra(num/10, k-1);
}

void leggi (int *x){
    do{
        scanf("%d", x);
    } while(*x<0);
}