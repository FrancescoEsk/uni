#include <stdio.h>

/*
Scrivere un sottoprogramma che ricevuto in ingresso un
numero intero, calcola e restituisce il numero intero ottenuto
mettendo le cifre in ordine opposto. Per esempio, se il valore
ricevuto in ingresso e 1245 il sottoprogramma restituisce 5421.
Se il valore ricevuto in ingresso e 190 il sottoprogramma
restituisce 91.
*/

int opp(int);

int main(void){
    int n;
    do{
        printf("Inserisci n: ");
        scanf("%i", &n);
    } while(n<=0);
    
    printf("%i\n", opp(n));
    return 0;
}

int opp (int x){
    int save = x;
    int n=0, count=-1, pow;

    while (save>0){ // conta le cifre
        save /= 10;
        count++;
    }

    while (x>0){
        pow=1;
        for(int i=0; i<count;i++) // calcola la potenza di 10 necessaria per mettere la cifra al posto giusto
            pow *= 10;

        n += (x % 10) * pow;
        x /= 10;
        count--;
    }

    return n;
}