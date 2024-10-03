#include <stdio.h>
#define DIM 20
/*
Si scriva un programma con una funzione con il seguente prototipo:
void inverti(char s[])
per invertire una stringa s di massimo 20 caratteri (ad esempio “ciao” diventa “oaic”). 
Scorrere la stringa (senza spazi) usando l’aritmetica dei puntatori
Scrivere la funzione main() per testare la funzione creata.
*/

void inverti(char[]);
int stlen(char[]);
void scambia(char[], int, int);

int main(void){
    char s[DIM+1];
    scanf("%s", s);
    inverti(s);

    printf("%s\n", s);
    return 0;
}

int stlen(char s[]){
    int i;
    for(i=0; s[i]!='\0'; i++){}
    return i;
}

void scambia(char s[], int x, int y){
    int temp = s[x];
    s[x] = s[y];
    s[y] = temp;
}

void inverti(char s[]){
    int dim = stlen(s), x;
    x = dim-1;
    for(int i=0; i<dim/2; i++){
        scambia(s, i, x);
        x--;
    }
}