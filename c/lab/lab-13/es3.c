#include <stdio.h>
#define DIM 20
/*
Si scriva un programma con una funzione con il seguente prototipo:
void scambia(char s[])
che scambi il primo carattere della stringa s (stringa senza spazi di massimo 20 caratteri)
 con l’ultimo. Scorrere la stringa usando l’aritmetica dei puntatori.

Scrivere la funzione main() per testare la funzione creata.
*/

void scambia(char[], int);
int stlen(char[]);

int main(void){
    char s[DIM+1];
    scanf("%s", s);
    scambia(s, stlen(s));
    printf("%s\n", s);
    return 0;
}

int stlen(char s[]){
    int i;
    for(i=0; s[i]!='\0'; i++){}
    return i;
}

void scambia(char s[], int x){
    int temp = s[0];
    s[0] = s[x-1];
    s[x-1] = temp;
}