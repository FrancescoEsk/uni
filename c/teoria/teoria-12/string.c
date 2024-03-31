#include <stdio.h>
#include <string.h>
#define DIM 10
/*
Stringhe --> array di caratteri
char v[12]
segnaposto stringhe --> %s (nb. viene aggiunto automaticamente un \n (scritto \0) alla fine della stringa inserita)
scanf("%s", v) --> non va messo &v !!

libreria per manipolare le stringhe   <string.h>
--> strlen(v)       |   ritorna la lunghezza della stringa
--> gets(v)         |   come scanf ma si ferma solo quando si preme invio (\n), quindi legge anche gli spazi
--> strcmp(v1, v2)  |   confronta due stringhe, dice se le due sono uguali (0), v1>v2(1) e v2>v1(-1)
--> strcpy(v1, v2)  |   copia v1 in v2
--> strcat(v1, v2)  |   restituisce la concatenazione di v1 e v2
*/

int main(void){
    char v[DIM+1], v2[DIM+1]; // aggiungere un posto in più per il \0 automatico
    int len, cmp;
    scanf("%s", v);
    gets(v2);
    len = strlen(v);
    cmp = strcmp(v, v2);
    strcpy(v, v2);
    return 0;
}