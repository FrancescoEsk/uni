#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 30
/*
scrivere un sottoprogramma che date due stringhe le concatena salvando il risultato
in una stringa che occupa esattamente lo spazio necessario
*/

char *concat(char*, char*);

int main(void){

    char s1[DIM+1], s2[DIM+1];
    scanf("%s", s1);
    scanf("%s", s2);
    char *s;
    s = concat(s1, s2);
    printf("%s\n", s);

    free(s);
    return 0;
}

char *concat(char *s1, char *s2){
    char *s;
    s = malloc(sizeof((strlen(s1)+strlen(s2))*sizeof(char)));
    if(s == NULL){
        printf("Errore\n");
    } else {
        int i=0;

        for(i=0; s1[i]!= '\0' && i<DIM+1; i++){
            s[i] = s1[i];
        }

        for(int j=0; s2[j]!= '\0' && j<DIM+1; j++){
            s[i] = s2[j];
            i++;
        }
    }
    return s;
}