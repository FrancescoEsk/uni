#include <stdio.h>
/*
Scrivere una funzione ricorsiva
 int potenza(int base, int esp)
che riceve due parametri e calcola l’elevamento a potenza (nel caso di esponente positivo).
Scrivere la funzione:
 int leggi(int min)
che acquisisce da tastiera un numero >= min.
Scrivere la funzione main() per testare la funzione realizzata.
*/

int potenza(int, int);
void leggi(int*);

int main(void){
    int x, y;
    leggi(&x);
    leggi(&y);
    printf("%d\n", potenza(x, y));
    return 0;
}

int potenza(int base, int esp){
    if(esp==0)
        return 1;
    if(esp==1)
        return base;
    else
        return base * potenza(base, esp-1);
}

void leggi (int *x){
    do{
        scanf("%d", x);
    } while(*x<0);
}