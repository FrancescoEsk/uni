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

Per svolgere l'esercizio si richiede l'implementazione di queste due
funzioni:
1) insertTime: creazione di una variabile strutturata contentente
l’orario chiedendo all’utente in input ore, minuti e secondi e
controllando la validità con la funzione checkTime
2) checkTime: controllo della validità: input ore, minuti e secondi, la
funzione restituisce 1 se i valori dei suoi campi sono validi, 0 in caso
contrario. Il campo ore deve avere valori compresi tra 0 e 23, mentre
i campi minuti e secondi devono avere valori tra 0 e 59.
*/

typedef struct{
    int ore;
    int minuti;
    int secondi;
} time;

time insertTime(time);
int checkTime(int, int, int);

int main(void){
    time t1, t2, t;

    printf("Primo instante di tempo: \n");
    t1 = insertTime(t1);
    
    printf("Secondo instante di tempo: \n");
    t2 = insertTime(t2);
    
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

time insertTime(time t){
    int o, m, s;
    do {
         printf("Inserisci ore minuti secondi: ");
        scanf("%d", &o);
        scanf("%d", &m);
        scanf("%d", &s);
        if (checkTime(o, m, s) == 1){
            t.ore = o;
            t.minuti = m;
            t.secondi = s;
        }
    } while (checkTime(o, m, s) == 0);
   
    return t;
}

int checkTime(int ore, int minuti, int secondi){
    if ( (ore >= 0 && ore <24) && (minuti>=0 && minuti <60) && (secondi>=0 && secondi<60) )
        return 1;
    else
        return 0;
}