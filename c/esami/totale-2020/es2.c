#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Completare il file ESA 23072019 A 2.c scrivendo un sottoprogramma rightshift che ricevuta in ingresso una
stringa sorgente e un numero intero senz’altro positivo n, modifica la stringa in modo tale che la stringa finale
sia quella iniziale, fatta scorrere di n posizioni a destra (con gli ultimi n caratteri riportati all’inizio). Se per
esempio la stringa iniziale `e Esempio ed n `e 1, la stringa finale sar`a oEsempi, se n `e 2, la stringa finale sar`a
ioEsemp
*/

void rightshift(char*, int);

int main(void){
    char str[] = "Esempio";
    int n = 2;

    rightshift(str, n);

    printf("Stringa finale: %s\n", str);
    return 0;
}

void rightshift(char *s, int n){
    if(n<=0) return;

    int len = strlen(s);
    char last = s[len-1];
    
    for(int i=len-1; i>0 ; i--)
        s[i] = s[i-1];
    s[0] = last;

    rightshift(s, n-1);
}