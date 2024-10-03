#include <stdio.h>
#define N 20
/*
Scrivere un programma C che:
 Richiede all’utente di inserire 20 caratteri e li salva in un array.
 Produce due risultati:
 Una array costruito con i caratteri inseriti in cui ogni 
vocale (mauiscola o minuscola) è sostituita da un numero 
corrispondente (A=1, E=2, I=3, O=4, U=5).
 Un numero contenente la somma delle cifre (caratteri da 0 
a 9) contenute nella stringa prodotta.
*/

int main(void){
    char a[N];

    for(int i=0; i<N; i++){
        printf("Inserisci il carattere numero %i: ", i+1);
        scanf(" %c", &a[i]);
    }

    char b[N];
    int somma=0;
    for(int i=0; i<N; i++){
        if (a[i]=='A' || a[i]== 'a'){
            b[i] = '1'; somma++;
        }
        else if (a[i]=='E' || a[i]== 'e'){
            b[i] = '2'; somma += 2;
        }
        else if (a[i]=='I' || a[i]== 'i'){
            b[i] = '3'; somma += 3;
        }
        else if (a[i]=='O' || a[i]== 'o'){
            b[i] = '4'; somma += 4;
        }
        else if (a[i]=='U' || a[i]== 'u'){
            b[i] = '5'; somma += 5;
        }
        else{
            b[i] = a[i];
            switch (a[i]){
                case('1'):somma++;
                case('2'):somma+=2;
                case('3'):somma+=3;
                case('4'):somma+=4;
                case('5'):somma+=5;
                case('6'):somma+=6;
                case('7'):somma+=7;
                case('8'):somma+=8;
                case('9'):somma+=9;
            }
        }
    }

    for(int i=0; i<N; i++){
        printf("%c ", b[i]);
    }
    printf("La somma dei numeri nell'array è: %i\n", somma);
    return 0;
}