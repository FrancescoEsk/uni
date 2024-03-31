#include <stdio.h>
#include <string.h>
#define C 5
#define M 20
#define N1 365
#define N2 50

/*
scrivere un prog c con una serie di sottoprog per la gestione dei voli aerei:

- volo aered -> struttura 
    codice (stringa max 5 char)
    città di partenza (stringa max 20 char)
    città di arrivo (stringa max 20 char)
    num posti liberi per ciascun giorno dell'anno
        (array di 365 elementi interi)

- gestire al massimo 50 voli --> array di struct di max 50 elementi
*/

typedef struct {
    char cod[C], part[M], arr[M];
    int posti[N1], maxp;
    float costo;
} volo;

typedef struct{
    volo vol[N2];
    int n; // max voli
} voli;


void inserisciVolo(voli*); // 0 - inserimento di un nuovo volo
void visualizzaVoli(voli*); // 1 - visualizzare tutti i voli
void prenotaVolo(voli*); // 2 - prenotare un volo specificando il codice e il giorno
void visualizzaPostiLiberi(voli*); // 3 - visualizzare num posti disponibili per un volo, specificando codice e giorno
void cancellaVolo(voli*); // 4 - cancellare un volo in base al codice
void mostraVoli(voli*); // 5 - mostrare tutti i voli che collegano due città
// 6 - uscire dal programma
void mostraMenu(); // mostra il menu'

int main(void){
    voli v;
    int x;
    v.n = 0;
    do{
        mostraMenu();
        scanf("%d", &x);
        switch (x)
        {
            case 0: inserisciVolo(&v);
            case 1: visualizzaVoli(&v);
            case 2: prenotaVolo(&v);
            case 3: visualizzaPostiLiberi(&v);
            case 4: cancellaVolo(&v);
            case 5: mostraVoli(&v);
        }
    } while(x!=6);
    return 0;
}

void inserisciVolo(voli *v){
    int ok=1;
    if (v->n > N2)
        printf("Non c'e' piu' spazio!\n");
    else{
        do{
            printf("Codice: ");
            scanf("%s", v->vol[v->n].cod); // recupero il num di voli che ho inserito, così so in che posiz accedere per uno nuovo
            for(int i=0; i<v->n && ok==1; i++){
                if(strcmp(v->vol[i].cod, v->vol[v->n].cod) == 0){
                    ok=0;
                } // controllo che il codice inserito non esista gia'

            }
        } while(ok==0);

        do{
            printf("Citta' di partenza: ");
            scanf("%s", v->vol[v->n].part);

            printf("Citta' di arrivo: ");
            scanf("%s", v->vol[v->n].arr);

        } while(strcmp(v->vol[v->n].part, v->vol[v->n].arr)==0);
        
        do{
            printf("Costo: ");
            scanf("%f", &(v->vol[v->n].costo));
        } while (v->vol[v->n].costo < 0);

        do{
            printf("Numero massimo passeggeri: ");
            scanf("%d", &(v->vol[v->n].maxp));
        } while (v->vol[v->n].maxp < 0);

        printf("Num posti liberi per ogni giorno dell'anno: \n");
        for(int z=0; z<N1; z++){
            v->vol[v->n].posti[z] = v->vol[v->n].maxp;
        }
        v->n++;
    }
}

void visualizzaVoli(voli *v){
    for(int i=0; i<v->n; i++){
        printf("Codice: %s\nCitta' di partenza: %s\nCitta' di arrivo: %d\n", v->vol[i].cod, v->vol[i].part, v->vol[i].arr);
        printf("Costo: %.2f\nNumero massimo di passeggeri: %d\n", v->vol[i].costo, v->vol[i].maxp);
    }
}

void visualizzaPostiLiberi(voli *v){
    char x[C];
    int check=0;
    do{
        printf("Inserisci il codice del volo: ");
        scanf("%s", x);
        for(int i=0; i<v->n && check==0; i++){
            if(strcmp(v->vol[i].cod, x) == 0){
                printf("Num posti liberi per ogni giorno dell'anno: \n");
                for(int z=0; z<N1; z++){
                    printf("Giorno %d: %d", z+1, (v->vol[i].posti)[z]);
                }
                check = 1;
            }
        }
    } while (check==0);
}

void prenotaVolo(voli *v){
    char x[C];
    int check=0, n, inp;
    do{
        printf("Inserisci il codice del volo: ");
        scanf("%s", x);
        for(int i=0; i<v->n && check==0; i++){
            if(strcmp(v->vol[i].cod, x) == 0){
                do{
                    printf("Inserisci il giorno da prenotare: ");
                    scanf("%d", &n);
                } while(n<0 || n>N1);
                
                if((v->vol[i].posti)[n] > 0){
                    (v->vol[i].posti)[n]--;
                    printf("Prenotato\n");
                    check = 1;
                } else{
                    printf("Nessun posto disponibile per il giorno selezionato. Cambiare giorno o uscire(0)? ");
                    scanf("%d", inp);
                    if(inp==0)
                        check = 1;
                }
            }
        }
    } while (check==0);
}

void cancellaVolo(voli *v){
    char x[C];
    int check=0, n;
    do{
        printf("Inserisci il codice del volo: ");
        scanf("%s", x);
        for(int i=0; i<v->n && check==0; i++){
            if(strcmp(v->vol[i].cod, x) == 0){
                printf("Sicuro di cancellare questo volo(1)? ");
                scanf("%d", &n);
                if(n==1){
                    // cancello volo e shifto tutto a sx di 1 dal posto libero
                }
                check=1;
            }
        }
    } while (check==0);
}

void mostraVoli(voli *v){

}

void mostraMenu(){
    printf("0 - inserimento di un nuovo volo\n");
    printf("1 - visualizzare tutti i voli\n");
    printf("2 - prenotare un volo specificando il codice e il giorno\n");
    printf("3 - visualizzare num posti disponibili per un volo, specificando codice e giorno\n");
    printf("4 - cancellare un volo in base al codice\n");
    printf("5 - mostrare tutti i voli che collegano due città\n");
    printf("6 - uscire dal programma\n");
}