#include <stdio.h>
#include <string.h>
#define DIM 100

/*
Scrivere un programma C che richiede
all'utente due parole, crea una parola che corrisponde alla
loro concatenazione e la scrive a video.
*/

int main(void){
    char str1[DIM+1], str2[DIM+1];
    scanf("%s", str1);
    scanf("%s", str2);
    
    printf("%s\n", strcat(str1, str2));
    return 0;
}