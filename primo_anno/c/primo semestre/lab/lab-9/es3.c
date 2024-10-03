#include <stdio.h>

/*
Scrivere un sottoprogramma che dati due interi, verifica
se il primo è multiplo del secondo e restituisce 1 o 0 al
chiamante
3 12 --> 12 è multiplo di 3
*/

int multiplo(int, int);

int main(void){
    int n1, n2;
    printf("Inserisci numero 1: ");
    scanf("%i", &n1);
    printf("Inserisci numero 2: ");
    scanf("%i", &n2);

    printf("%i\n", multiplo(n1, n2));
    return 0;
}

int multiplo(int a, int b){
    if (b%a == 0)
        return 1;
    return 0;
}