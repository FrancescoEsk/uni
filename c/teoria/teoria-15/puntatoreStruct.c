#include <stdio.h>
/*
Puntatore con struct


*/

typedef struct{
    int x, y;
} punto_t;

int main(void){
    punto_t p;
    p.x;
    p.y;

    punto_t *a; // puntatore ad una struttura punto_t

    (*a).x; // accedere alla struttura puntata, e poi accedo ai suoi membri (x o y)
    a -> x; // equivalente alla riga sopra, piu' veloce anche da scrivere
    
    return 0;
}