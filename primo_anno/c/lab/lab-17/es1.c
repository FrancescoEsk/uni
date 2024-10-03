#include <stdio.h>
#include <stdlib.h>
/*
Si vuole gestire una classe di studenti tramite un array di dimensione variabile; 
le informazioni degli studenti hanno la seguente definizione di tipo:
struct t_stud{
    char nome[21];
int eta; };
oppure
typedef struct {
    char nome[21];
    int eta;
} t_stud;
Scrivere una funzione C che prende come parametro il numero di studenti da inserire e 
che restituisce l’indirizzo dell’array dinamico. I nomi e le età vengono lette da tastiera. 
Gestire eventuali errori nella fase di allocazione di memoria, restituendo NULL in caso di errori, 
l’indirizzo del vettore in caso di successo.
*/

typedef struct {
    char nome[21];
    int eta;
} t_stud;

int main(void){
    int n;
    t_stud *a;
    scanf("%d", &n);
    a = (t_stud *) malloc(sizeof(t_stud)*n);
    if(a != NULL){
        for(int i=0; i<n; i++){
            printf("Inserisci nome: ");
            scanf("%s", a[i].nome);
            printf("Inserisci età: ");
            scanf("%d", &a[i].eta);
        }
        
    } else {
        printf("Errore\n");
    }

    free(a);
    return 0;
}