#include <stdio.h>
#include <string.h>
#define LIMIT 50
/*
Esercizio: Inversione di una stringa letta da un file utilizzando la ricorsione

Scrivi un programma in C che legge una stringa da un file.
Il programma dovrebbe invertire la stringa utilizzando una funzione ricorsiva.
Infine, il programma dovrebbe stampare la stringa invertita.
*/

void inverti(char*, int, int pos);

int main(void){
    FILE *fp = fopen("dizionario.txt", "r");
    if(fp == NULL){
        printf("errore apertura file\n");
        return -1;
    }
    char s[LIMIT+1];
    while( !feof(fp) ){
        fscanf(fp, "%s", s);
        printf("%s --> ", s);
        inverti(s, strlen(s)-1, 0);
        printf("%s\n", s);
    }
    return 0;
}

void inverti(char *s, int len, int pos){
    if(pos >= len-pos){
        return;
    }

    char tmp = s[pos];
    s[pos] = s[len-pos];
    s[len-pos] = tmp;
    return inverti(s, len, pos+1);
}
