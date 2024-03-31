#include <stdio.h>

/*
.Scrivere un programma che inverta la posizione delle cifre di un numero 
intero inserito dall’utente (4321 > 1234). Inoltre, il programma avvisa se il 
numero inserito è palindromo (si legge allo stesso modo da sinistra a destra e 
viceversa, es: 121, 32123, …).
*/

int main(void){
    int n, x, count=0, ris, pow=1, num;
    printf("Inserisci il numero da invertire: ");
    scanf("%i", &n);
    x = n; // salvo il numero per manipolarlo
    while((x/10)>0){
        count++; // conto le cifre del numero
        x /= 10;
    }
    num = n;
    while (count>0){
        pow = 1; // imposto la pow a 1
        x = n%10; // ottengo la cifra del numero
        for (int i=0; i<count; i++) // creo la potenza di 10 
            pow *= 10;
        ris += x*pow; // e moltiplico la cifra tolta per la pow di 10 corretta
        count--;
        n /= 10; // diminuisco il numero
    }

    printf("Il numero invertito è: %i\n", ris);

    if ( ris == num ) // se il numero iniziale è uguale al suo invertito
        printf("Il numero è inoltre palindromo\n");
    return 0;
}

// ALTRO MODO PER FARLO

int swap(int n){
    int num=n, rev=0, temp;

    while(num>0){
        temp = num%10; // tolgo la cifra (631 --> 1) --> (63 --> 3) --> 6
        rev = rev*10 + temp; // costruisco il numero invertito (0*10+1) --> (1*10 + 3) --> 13*10 + 6 --> 136
        num /= 10;
    }

    /*
    if (rev == n)
        printf("Il numero è inoltre palindromo\n");
    */
    return rev;
}