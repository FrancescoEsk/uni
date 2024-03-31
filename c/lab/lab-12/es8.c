#include <stdio.h>
#include <string.h>
#define DIM 50
/*
 Scrivere un programma C che acquisisca una 
stringa s1 di massimo 50 caratteri e un numero 
intero n. 

 Il programma controlla se n è maggiore di zero e 
minore della lunghezza della stringa e, se le 
condizioni non sono verificate continua a 
richiedere il valore; poi il programma crea una 
nuova stringa s2 che contiene la rotazione 
(spostamento) verso destra di s1 di n posizioni e 
la visualizza.
 Esempio: s1="studente" e n=2 -> s2="udentest"
*/

void swap(char*, char*);
void shift(char[DIM+1], int, char*);

int main(void){
    int n;
    char str[DIM+1];
    do{
        scanf("%s", str);
        scanf("%d", &n);
    }while(n>0 && n<strlen(str));
    char str2[DIM+1];
    shift(str, n, &str2);
    return 0;
}

void swap(char *n1, char *n2){
    char temp = *n2;
    *n2 = *n1;
    *n1 = temp;
}

void shitf(char s[DIM+1], int n, char *s2){
    char temp;
    int x = strlen(s);
    for(int i=0; i<n; i++){
        
        for(int z=x; z>=0; z++){
            if (z==0)
                swap(s[z-1+x], s[z]);
            else
                swap(s[z-1], s[z]);
        }

    }
    *s2 = s;
}