#include <stdio.h>
#define pi 3.14
/*
PUNTATORE

passaggio dei parametri 
- per valore
- per riferimento / indirizzo

riferimento
- modifiche permanenti
- funzioni che possono ritornare più di un valore

* def variabile di tipo puntatore (int *p)
& operatore di referenziazione -> recupera l'indirizzo di una variabile ( p = &x)

-------------
scrivere un sottoprogramma che calcola l'area ed il perimetro
di un cerchio di raggio dato dall'utente.

*/

void cerchio(float, float*, float*);

int main(void){
    float r, area, perim;
    scanf("%d", &r);
    cerchio(r, &area, &perim);
    printf("%.01f %.01f\n", area, perim);
    return 0;
}

void cerchio(float r, float *a, float *p){
    *p = r*pi*2;
    *a = r*r*pi;
}