#include <stdio.h>
#include <stdlib.h>
/*
Si completi il file ESI 21062023 A 1.c scrivendo le seguenti funzioni:
1. run length, che data una stringa s e un carattere c, restituisce il numero di caratteri c consecutivi
presenti all’inizio della stringa s
2. count run lengths, che data una stringa s, ritorna il numero di sequenze di caratteri consecutivi presenti
nella stringa di ingresso.
Il programma chieder`a in ingresso una stringa e stamper`a a video il numero di sequenze di caratteri consecutivi
presenti nella stringa inserita. Ad esempio, se la stringa fosse ”aaaaabbbbbbaa” verr`a stampato 3, perch`e ci
sono tre sequenze: una sequenza di ’a’, una sequenza di ’b’ e una sequenza di ’a’
*/

int run_length(char*, char);
int count_run_lengths(char*);

int main(void){
    printf("%d\n", count_run_lengths("aaaaabbbbbbaa"));
    return 0;
}

int run_length(char *s, char c){
    int count=0;
    for(int i=0; s[i] != '\0'; i++){
        // printf("%c ", s[i]);
        if(s[i] == c){
            count++;
        }

        if(s[i] != c && count)
            return count;
    }
    return count;
}

int count_run_lengths(char *s){
    int count=0, temp, len=0;

    for(int i=0; s[i] != '\0'; i++) len++;

    for(int i=0; s[i] != '\0' && i<len; i++){
        printf("%c ", s[i]);
        temp = run_length(s, s[i]);
        if(temp>1) count++;
        i += temp-1;
    }

    return count; 
}