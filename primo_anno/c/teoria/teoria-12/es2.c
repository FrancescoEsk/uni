#include <stdio.h>
#include <string.h>
#define DIM 30
/*
scrivere un programma (tutto nel main) che acquisisce una stringa (scanf o gets) di 
al più 30 caratteri, la copia a rovescio in un secondo array e visualizza il risultato
*/

int main(void){
    char str1[DIM+1];
    char str2[DIM+1];
    int k=0, len;
    scanf("%s", str1);
    len = strlen(str1); // ottengo la lunghezza della stringa
    for(int i=len-1; i>=0; i--){
        str2[i] = str1[k]; // la copio al contrario
        k++;
    }
    str2[len] = '\0'; // aggiungo lo \0
    printf("%s\n", str2); // stampo
    return 0;
}