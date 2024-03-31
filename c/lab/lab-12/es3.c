#include <stdio.h>
/*
 Scrivere una funzione 
void sum(double *s, double x, double y)
 Che assegna la somma tra il secondo e il terzo 
argomento (passati per valore) al primo argomento 
(passato per riferimento).
 La funzione deve essere richiamata dalla funzione 
main, la quale si occupa anche di richiedere due 
double all’utente e stampare il risultato.
*/

void sum(double*, double, double);

int main(void){
    double a, b, *s;
    scanf("%le", &a);
    scanf("%le", &b);
    sum(s, a, b);
    printf("%.01le\n", *s);
    return 0;
}

void sum(double *s, double x, double y){
    *s = x + y;
}