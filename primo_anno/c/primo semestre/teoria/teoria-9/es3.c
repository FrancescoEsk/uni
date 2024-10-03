#include <stdio.h>
#define N 10
/*
richiede 10 numeri interi all'untente, messi in un array e fatta la media 2 a 2
*/

int input();
float media(int, int);

int main(void){
    int a[N];
    for (int i=0; i<N; i++)
        a[i] = input();
    
    for (int i=0; i<N-1; i+=2)
        printf("Media tra %i e %i: %.2f\n",a[i], a[i+1], media(a[i], a[i+1]));
    
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