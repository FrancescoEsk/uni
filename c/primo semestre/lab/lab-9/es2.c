#include <stdio.h>
#define N 14

/*
Si scriva un programma non scomposto in sottoprogrammi per calcolare la
media dei voti sufficienti riportati da una classe di studenti all'esame di
Programmazione I.

Il programma dovrà leggere coppie di numeri e memorizzarle in un array di
apposite struct.

Ciascuna coppia è composta dal voto (tra 18 e 31) e dal numero di studenti che
hanno riportato quel voto e la sequenza termina dopo aver letto al massimo le 14
coppie (anche non in ordine) oppure quando si introduce un voto pari a -1.
Per esempio, una sequenza di coppie potrebbe essere:

<18, 1>, <19, 2>, <26, 9>, -1
che indica che uno studente ha riportato voto 18,
2 studenti hanno riportato voto 19 e
9 studenti hanno riportato voto 26.

In questo caso il programma dovrebbe stampare il
valore 24.16 come media complessiva dei voti.

L'array da utilizzare deve contenere delle struct
composte da un campo voto e da un campo num_studenti.
*/

typedef struct{
    int voto;
    int num_studenti;
} coppia;

int main(void){
    int i=0;
    int temp;
    float media=0;
    float count=0;
    coppia c[N]; // array di struct

    do{ 
        do{
            printf("Inserisci il voto: ");
            scanf("%i", &temp);
        } while ((temp<18 || temp>31) && temp!=-1);
        
        if (temp != -1){
            c[i].voto = temp;
            printf("Inserisci il num studenti: ");
            scanf("%i", &c[i].num_studenti);

            media += (float)c[i].voto;
            count += c[i].num_studenti;

            i++;
        }
    } while(i<N || temp != -1);

    printf("Media complessiva dei voti: %.2f\n", media/count);

    return 0;
}