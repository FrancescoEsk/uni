#include<stdio.h>
#define DIM 10
// prototipi
int conta(char *, int*);
void cambia(char *, int);

int main(){
  char frase[]="Oggi conta tutte le doppie in questa frase";
  char frase2[]="Qui non ci sono ripetizioni";
  int doppie;
  int parole=0;
  
  doppie=conta(frase,&parole);
  printf("\nCi sono %d doppie e %d parole in %s",doppie,parole,frase);
  parole=0;
  doppie=conta(frase2,&parole);
  printf("\nCi sono %d doppie e %d parole in %s",doppie,parole,frase2);
  cambia(frase,0);
  printf("\n La frase diventa: %s",frase);
  cambia(frase2,0);
  printf("\n La frase diventa: %s",frase2);
}

//conta restituisce il numero di doppie e scrive nel parametro word il numero di parole
int conta(char *f,int *word){
  int dopp=0;
  *word = 1;
  for(int i=0; f[i]!= '\0'; i++){
    if(f[i] == f[i-1])
      dopp++;
    if(f[i] == " ")
      *word = *word +1;
  } 

  return dopp;
}
		
/* 
funzione RICORSIVA che sposta a destra di una posizione tutti i caratteri della stringa, a partire da pos, l'ultimo carattere - non terminatore - diventa il primo	
NON USARE ARRAY DI SUPPORTO
*/	
void cambia(char *f, int pos) {
    static char ultimo;
    if (f == NULL || *f == '\0') {
        return;
    }

    // Salva l'ultimo carattere
    if (pos == 0) {
        ultimo = *f;
    }

    // Chiama la funzione ricorsivamente
    cambia(f + 1, pos + 1);

    // Sposta i caratteri
    if (*(f + 1) != '\0') {
        *f = *(f + 1);
    } else if (pos == 0) {
        *f = ultimo;
    }
}

