#include <stdio.h>
/*
tramite typedef posso dichiarare un certo tipo di puntatore

typedef int* intPtr; 

così posso dichiarare più puntatori alla volta
--> intPtr a, b, c; // come int *a, *b, *c;
-------

*/

typedef int* intPtr; // puntatore ad un intero
typedef intPtr* int2Ptr; // puntatore ad un puntatore ad un intero

int main(void){
    int c, d;
    intPtr p1, p2;
    int2Ptr pp1, pp2;

    c = 54;
    d = 10;

    p1 = &c; // punta a c
    p2 = p1; // punta a c

    printf("%d %d %d %d\n", c, d, *p1, *p2);

    p1 = &d;
    *p1 = *p1 + *p2;

    printf("%d %d %d %d\n", c, d, *p1, *p2);

    pp1 = &p1;
    pp2 = &p2;

    *pp2 = *pp1;

    return 0;
}