#include <stdio.h>
/*
data una sequenza di numeri contare quante volte
compaiono numeri dispari consecutivi (-1 per terminare)

3 7 8 5 7 9 4 6 7 -1

sequenze = 3;
*/

int disp(int);

int main(void){
    int x, c=0, r=0;
    do{
        printf("Inserisci numero: ");
        scanf("%i", &x);
        if (disp(x)) // se dispari conto
            c++;
        else // sennò reset
            c=0;
        if (c>1) // se maggiore di uno conto la sqnz
            r++; 
    } while (x!= -1); // -1 = termino
    printf("Sequenze di numeri dispari inserite: %i\n", r);
    return 0;
}

int disp(int a){ // se dispari da 1, alrim 0
    if (a%2==1)
        return 1;
    else
        return 0;
}