#include <stdio.h>
#define N 4
/*
calcolare il coefficiente binominale dei numeri a e b

--> quanti sottoinsiemi di b elementi posso creare da un insieme di a elementi

esempio

1 2 3 4
a = 4
b = 2

1 2 
1 3
1 4
2 3
2 4
3 4
totale: 6

formula:
a! / (b! * (a-b)!)
*/

int main(void){
    int a, b, aF, bF, abF;

    printf("Inserisci a: ");
    scanf("%i", &a);
    printf("Inserisci b: ");
    scanf("%i", &b);
    for(int i=1; i<=a; i++){
        aF *= i;
    }
    for(int i=1; i<=b; i++){
        bF *= i;
    }
    for(int i=1; i<=(a-b); i++){
        abF *= i;
    }

    printf("Coefficiente binominale: %i", aF/(bF * abF));

    // sarebbe da semplificare i for con una FUNZIONE
    return 0;
}