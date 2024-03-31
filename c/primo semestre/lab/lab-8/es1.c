#include <stdio.h>

/*
Scrivere un programma C che calcola il tempo trascorso
(in ore, minuti e secondi) tra due istanti di tempo, che
vengono chiesti all’utente.
Definire una struttura time che contiene ora, minuti e
secondi.
Es.
Il tempo trascorso tra 3:45:15 e 9:44:03 è
5 ore, 58 minuti e 48 secondi..
*/

struct time{
    int ore;
    int minuti;
    int secondi;
};


int main(void){
    struct time t1, t2, t;

    printf("Primo instante di tempo: \n");
    do{
        printf("Ore: ");
        scanf("%i", &t1.ore);
    } while (t1.ore < 0);
    do{
        printf("Minuti: ");
        scanf("%i", &t1.minuti);
    } while (t1.minuti < 0 || t1.minuti > 59);
    do{
        printf("Secondi: ");
        scanf("%i", &t1.secondi);
    } while (t1.secondi < 0 || t1.secondi > 59);
    
    printf("Secondo instante di tempo: \n");
    do{
        printf("Ore: ");
        scanf("%i", &t2.ore);
    } while (t2.ore < 0);
    do{
        printf("Minuti: ");
        scanf("%i", &t2.minuti);
    } while (t2.minuti < 0 || t2.minuti > 59);
    do{
        printf("Secondi: ");
        scanf("%i", &t2.secondi);
    } while (t2.secondi < 0 || t2.secondi > 59);
    
    t.ore = t2.ore - t1.ore;
    t.minuti = t2.minuti - t1.minuti;
    t.secondi = t2.secondi - t1.secondi;
    if (t.minuti<0){
        t.minuti += 60;
        t.ore--;
    }
    if (t.secondi<0){
        t.secondi += 60;
        t.minuti--;
    }

    printf("Il tempo trascorso tra %i:%i:%i e %i:%i:%i e' %i ore, %i minuti e %i secondi.\n", 
    t1.ore, t1.minuti, t1.secondi, t2.ore, t2.minuti, t2.secondi, t.ore, t.minuti, t.secondi);

    return 0;
}