#include <stdio.h>
/*
altro esempio con i puntatori
*/

int main(void){
    int a, b, *aPtr, *bPtr, s;
    // int a, b, somma;

    // scanf("%d", &a); 
    // ...
    scanf("%d", &a);
    scanf("%d", &b);
    aPtr = &a;
    bPtr = &b;
    // s = a+b;
    s = *aPtr + *bPtr;

    printf("%d\n", s);

    // avessi scritto
    // printf("%p\n", sPtr);
    // avrei stampato l'indirizzo di memoria a cui punta il puntatore sPtr
    return 0;
}