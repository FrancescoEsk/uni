#include <stdio.h>
#include <stdlib.h>
#define DIM 25
/*
il sottoprogramma parola_valida che prende in input una stringa, un intero n ed un intero k e restituisce 1 
se la stringa ricevuta in ingresso è lunga almeno n caratteri e contiene almeno k cifre (caratteri numerici), 0 altrimenti.
il sottoprogramma conta_valide che riceve in ingresso un intero n ed un intero k, apre il file "origine.txt" che contiene
 un insieme di parole, e restituisce il numero delle parole valide (ovvero che contengono almeno n caratteri e almeno k cifre).
Le parole presenti nel file di origine sono di al più 25 caratteri, una per riga. Nel caso in cui ci siano problemi di accesso al file,
 il sottoprogramma restituisce -1. 

Per esempio, se il sottoprogramma riceve in ingresso 8 e 2, ed il file origine.txt contiene le parole:
 ammirato programmazione1 programmazione23 val1d023 il sottoprogramma stampa 2 (sono valide le parole programmazione23 e val1d023).
*/

int parola_valida(char*, int, int);
int conta_valide(int, int);

int main(void){
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    printf("%d\n", conta_valide(a, b));
    return 0;
}

int parola_valida(char *s, int n, int k){
    int count=0, countk=0;
    for(int i=0; s[i] != '\0'; i++){
        count++;
        if(s[i] >= '0' && s[i] <= '9')
            countk++;
    }
    if(count >= n && countk >= k) return 1;
    else return 0;
}

int conta_valide(int n, int k){
    FILE *fp = fopen("origine.txt", "r");
    char str[DIM]; 
    int count=0;

    if(fp == NULL)
        return -1;

    while(fgets(str, DIM, fp) != NULL){
        count += parola_valida(str, n, k);
    }

    fclose(fp);
    return count;
}