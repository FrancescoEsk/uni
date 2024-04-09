#include <stdio.h>
/*
Legge in input una sequenza di caratteri terminati dal tasto invio (10)
e stampi a video tale sequenza in ordine invertito.
Il programma stampi anche il numero di caratteri inseriti.

"abcdef<invio>"
--> "fedbca"
*/

int invertiChar();

int main(void){
    printf("\n%d\n", invertiChar());
    return 0;
}

int invertiChar(){
    int partresult;
    char c;
    scanf("%c", &c);
    if(c==10){
        return 0; // ritorno 0 se ho messo invio, in modo da poter iniziare a terminare la funzione
    } else {
        partresult = invertiChar(); // conto le volte che prendo un carattere valido
        printf("%c", c); // solo quando inserisco invio, l'ultima istanza continua e inizia a stampare (dall'ultimo fino al primo)
        return partresult+1; // sommo tutte le istanze per ottenere il numero di caratteri
    }
}