#include <stdio.h>
/*
sottoprogramma che riceve come parametro due numeri interi (richiesti all'utente) e restituisce la loro media
*/

int input();
float media(int, int);

int main(void){
    int a, b, c, d;
    a = input();
    b = input();
    c = input();
    d = input();

    printf("Media tra %i e %i: %.2f",a, b, media(a, b));
    printf("Media tra %i e %i: %.2f",c, d, media(c, d));
    return 0;
}

int input(){
    int x;
    printf("Inserisci un numero intero: ");
    scanf("%i", &x);
    return x;
}

float media(int a, int b){
    return ((a+b)/2.0);
}