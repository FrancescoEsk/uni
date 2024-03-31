#include <stdio.h>
/*
esempio di un semplice utilizzo di un puntatore
*/

int main(void){
    int *ptr, var1, var2; // ptr è puntatore ad intero, le altre sono variabili intere
    ptr = &var2; // assegno a ptr l'indirizzo di var2
    // scanf("%d", &var2);
    scanf("%d", ptr); // con ptr non è necessario usare & perchè ptr contiene già l'indirizzo di mem di var2

    *ptr++; // var2++;  grazie all'asterisco sto utilizzando la variabile che ho puntato
    // oppure *ptr = *ptr +1;
    printf("%d\n", *ptr); // printf("%d\n", var2);
    return 0;
}