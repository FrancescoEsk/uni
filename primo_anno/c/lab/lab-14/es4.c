#include <stdio.h>
/*
Si scriva un programma C che calcoli il
quoziente della divisione tra interi x e y usando
una funzione ricorsiva.
Caso base: x < y, allora il quoziente è zero.
Passo ricorsivo: il quozionte è 1 + il quoziente della
divisione di (x - y) per y.
●
●
Il programma dovrà contenere anche una funzione leggi() richiede all’utente un intero non negativo 
(controllare l’input). 
Tale funzione sarà chiamata due volte all’interno della funzione main() per inizializzare x e y.
*/

void leggi(int*);
int divisione(int, int);

int main(void){
    int x, y;
    leggi(&x);
    leggi(&y);
    printf("%d\n", divisione(x, y));
    return 0;
}

int divisione(int x, int y){
    if(x<y)
        return 0;
    else
        return 1 + divisione(x-y, y);
}

void leggi (int *x){
    do{
        scanf("%d", x);
    } while(*x<0);
}