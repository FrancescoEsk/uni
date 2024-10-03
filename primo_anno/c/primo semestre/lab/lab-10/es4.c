#include <stdio.h>
#define N 9

/*
Data una matrice NXN (con N=9) utilizzata per una semplificazione del gioco
Sudoku. Si scriva un programma C in grado di:

 Riempire la matrice da tastiera. In ogni cella della matrice dovrà comparire
soltanto un numero appartenente all’intervallo [1,9] (si devono rifiutare i valori
non appartenenti all’intervallo). Nessun altro vincolo deve essere rispettato in
fase di inizializzazione.

 Stampare la matrice a video.

 Chiedere all’utente l’inserimento da tastiera di un indice di riga r e un indice di
colonna c (rifiutando per entrambi eventuali valori non appartenenti
all’insieme {0,3,6}).

 Verificare se nel quadrato di dimensione 3X3 e origine nel punto (r,c), ogni
valore dell’intervallo [1,9] compare esattamente 1 volta. Stampare un
opportuno messaggio a video.

Ad esempio, se l’utente ha inizializzato la matrice mostrata nel prossimo lucido e
inserisce le coordinate (0,3) (r=0, c=3), nella sottomatrice di dimensione 3X3
evidenziata in grigio, ogni valore dell’intervallo [1,9] compare esattamente 1 volta.
Il programma dovrà stampare a video un messaggio del tipo “Proprietà
verificata”
*/

int main(void){
    int m[N][N];
    int r, c;

    for(int i=0;i<N;i++){ // inserimento
        for(int z=0;z<N;z++){
            do {
                printf("Inserisci: ");
                scanf("%i", &m[i][z]);
            } while (m[i][z]<1 || m[i][z]>9);
        }
    }

    for(int i=0;i<N;i++){ // stampa
        for(int z=0;z<N;z++)
            printf("%i ", m[i][z]);
        printf("\n");
    }

    do {
        printf("Inserisci r: ");
        scanf("%i", &r);
    } while (r != 0 && r!= 3 && r != 6);

    do {
        printf("Inserisci c: ");
        scanf("%i", &c);
    } while (c != 0 && c!= 3 && c != 6);

    int check[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int x, singolo = 1;

    for(int i=r;i<r+3;i++){ // check
        for(int z=c;z<c+3;z++){
            x = m[i][z];
            
            for (int k=0; k<N; k++) // sostituisco dall'array il numero in questione con 0
                if (x == check[k])  check[k] = 0;
        }
    }

    for (int k=0; k<N; k++) // se l'array non e' totalmente azzerato, il blocco non contiente tutti valori unici e diversi fra loro
        if (check[k] != 0)  singolo = 0;

    if (singolo)    printf("Proprieta' verificata\n");
    else    printf("Proprieta' non verificata\n");
    return 0;
}