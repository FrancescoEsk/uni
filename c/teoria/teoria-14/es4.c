#include <stdio.h>
#define DIM 30
/*
stringhe -> array di caratteri

funzione che calcola la lunghezza di una stringa
*/

int strlen(char[]);

int main(void){
    char s[DIM+1];
    int l;
    gets(s);
    l = strlen(s);
    printf("%d\n", l);
    return 0;
}

int strlen(char s[]){
    int i;
    for(i=0; s[i]!='\0';i++){}
    return i;
}