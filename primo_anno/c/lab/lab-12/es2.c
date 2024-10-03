#include <stdio.h>
/*
Aggiungete il codice che manca e scoprite gli indirizzi delle 
variabile x in foo1 e y in foo2. Che cosa notate? Riuscite 
a spiegare quello che succede?
*/

void foo1(int xval) {
    int x;
    x = xval;
    /* Stampate l'indirizzo e il valore di x */
    printf("ind: %p, val:%d\n", &x, x);
}

void foo2(int dummy) {
    int y;
    /* Stampate l'indirizzo e il valore di y */
    printf("ind: %p, val:%d\n", &y, y);
}

int main(void) {
    foo1(7);
    foo2(11);
    return 0;
}