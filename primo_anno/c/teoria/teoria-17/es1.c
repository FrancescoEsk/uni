#include <stdio.h>
/*
FILE - Contenitore di informazioni

Caratteristiche:
    - persistente
    - acceduto da più programmi

Operazioni:
    - creazione / cancellazione
    - scrittura / lettura
    - controllare degli errori

Due tipi:
    - file binari
    - file testuali --> informazioni = sequenze di caratteri

DESCRITTORE DEL FILE : 
struttura dati contentente
    - posizione corrente nel file ( sequenziale )
    - modalità di accesso ( lettura o scrittura )
    - stato dell'accesso ( errori )

--> salvati in una TABELLA DEI FILE APERTI  - RAM - ( nome file, cursore, modalità di accesso, ... )

OPERAZIONI DA ESEGUIRE PER POTER USARE UN FILE:

1. aprire un "flusso di comunicazione" --> aprire il file
-> recuperare il descrittore del file

2. accedere al file, lettura o scrittura --> eseguire le operazioni sul file

3. chiudere il "flusso di comunicazione" --> chiudere il file

FILE *fid;
puntatore ad una variabile di tipo file ( tipo di dato che rappresenta un descrittore di un file )

fid = fopen("nomefile.txt", modalità);   --> aprire il "flusso di comunicazione" con il file di "nome" nomefile
 
--> nome del file se si trova nella directory corrente, altrimenti il PATH relativo/assoluto
--> modalità è una stringa "w" (scrittura DISTRUTTIVA) "r" (lettura)

se non riesce ad aprire il file nella modalità richiesta 
restituisce il valore NULL

--> quindi CONTROLLARE IL VALORE RESTITUITO DA fopen();

fclose(fid); --> chiude il "flusso di comunicazione"

OPERAZIONI - lettura   
           - scrittura --> fprintf(fid, "Hello World %d\n", i); ( scrittura sequenziale, scrive una riga dopo l'altra )


Scrivere un programma C che apre un file "ciao.txt" in scrittura e vi scrive i numeri da 1 a 10
*/

int main(void){
    // creazione puntatore tipo FILE
    FILE *fid;
    // apro il "flusso di comunicazione" in scrittura
    fid = fopen("ciao.txt", "w");
    // controllo se l'operazione va a buon fine o meno
    if(fid){
        // stampa nel file dei numeri da 1 a 10
        for(int i=1; i<11; i++)
            fprintf(fid, "%d ", i);
        // vado a capo riga
        fprintf(fid, "\n");
        // chiudo il file
        fclose(fid);
    }else{ // se non ho aperto il file correttamente
        printf("Errore. File non aperto.\n");
    }
    return 0;
}