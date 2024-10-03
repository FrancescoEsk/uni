#include <stdio.h>
#define DIM 100
/*
 Scrivere un programma C che conta il numero di
spazi, tabulazioni e righe di un testo inserito da
terminale.

Testo (CTRL+D) per terminare:

Nel mezzo
del cammin
di nostra vita
Spazi: 4
Tabulazioni: 0
Righe (newline): 3

 È anche possibile redirigere l’input del programma da un file: ./esercizio_04 < porto_sepolto.txt
*/

int main(void){
    char s[DIM+1];
    int countT=0, countS=0, countR=0;

    scanf("%s", s);
    for(int i=0; s[i]!='\0'; i++){
        if(s[i]=='\t')
            countT++;
        if(s[i]== '\n')
            countR++;
        if(s[i]==' ')
            countS++;
    }

    printf("Spazi: %d\nTabulazioni: %d\nRighe (newline): %d\n", countS, countT, countR);
    return 0;
}