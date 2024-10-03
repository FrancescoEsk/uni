#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 50
#define INDEX_LINES 0
#define INDEX_CHARS 1
#define INDEX_LETTERS 2
/*
scrivere un programma che analizza il contenuto di un file restituendo il num di righe,
di caratteri e il numero di lettere
*/

void text_analisys(char[DIM], int*);
int count_letters(char[DIM]);

int main(void){
    FILE *fid;

    int data[] = {0, 0, 0};
    text_analisys("testo.txt", data);

    printf("Numero di linee: %d\n", data[INDEX_LINES]);
    printf("Numero di caratteri: %d\n", data[INDEX_CHARS]);
    printf("Numero di lettere: %d\n", data[INDEX_LETTERS]);

    return 0;
}

void text_analisys(char s[DIM], int *a){
    FILE *fid;

    if( (fid = fopen(s, "r"))){
        char s[DIM];
        do{
            fgets(s, DIM, fid);
            *(a+INDEX_LINES) += 1;

            if(s[strlen(s)-1] == '\n'){
                s[strlen(s)-1] = '\0';
            }

            *(a+INDEX_CHARS) += strlen(s);
            *(a+INDEX_LETTERS) += count_letters(s);
            
        } while (!feof(fid));

        fclose(fid);
    } else {
        printf("Errore\n");
    }
}

int count_letters(char s[DIM]){
    int x=0;
    for(int i=0; s[i]!= '\0'; i++)
        if(s[i]>='A' && s[i]<='z')
            x++;
    return x;
}