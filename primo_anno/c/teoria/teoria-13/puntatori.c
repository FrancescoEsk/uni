#include <stdio.h>
/*
PUNTATORI

nello stack contengo il contenuto di a e b
quando viene chiamata sum, vengono aggiunte le variabili x e y nello stack, copiando il valore di a e b.
alla fine di sum, queste due variabili vengono eliminate

In sostanza, bastavano due valori, ma ne ho usati in memoria 4. (IN QUESTO CASO)

ALTRO MODO DI ACCEDERE ALLA MEMORIA:    &   <-- puntatore

Un puntatore è una variabile che contiene un INDIRIZZO di MEMORIA. (riferito ad una variabile già presente in mem)
Motivi per utilizzarli:
-   possiamo modificare il valore delle variabili passate come argomento
-   permettono di ritornare più valori nelle funzioni (array, matrici ecc)
-   per gestire i casi in cui non si conosce a priori la cardinalità dei dati (lenght array unknown)
-   risparmiare spazio con grandi quantità di dati

COME SI DICHIARA?   int *ptr;    <--- puntatore ad un intero    (L'* E' SIMBOLO DI PUNTATORE)
int *ptr1, ptr2;     <--- ptr1 puntatore ad un intero, ptr2 è una variabile intera!
-> dovevo scrivere int *ptr1, *ptr2;

COME ASSEGNARE UN VALORE AD UN PUNTATORE?   &
int *ptr;
int a;
-->     ptr = &a;

ACCEDERE AL VALORE DI UN PUNTATORE
ptr

ACCEDERE AL CONTENUTO DELL'AREA DI MEMORIA PUNTATA
printf("%d", *ptr);
*ptr = 2; // come se stessi scrivendo a = 2;

*/

int sum(int x, int y){
    return x+y;
}

int main(void){
    int a, b;
    scanf("%i", &a);
    scanf("%i", &b);
    printf("%i\n", sum(a, b));
    return 0;
}