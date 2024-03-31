#include <stdio.h>
/*
 Scrivere un sottoprogramma che calcola la radice 
quadrata intera di un numero intero positivo. Il 
sottoprogramma riceve come parametro il 
numero intero ed un'altra variabile, passata per 
indirizzo, in cui memorizzare la radice intera. Il 
sottoprogramma restituisce 1 se la radice intera è 
precisa (il numero è un quadrato perfetto), in 
alternativa 0. Scrivere un programma che 
utilizza tale sottoprogramma per calcolare la 
radice quadrata intera di un numero chiesto 
all'utente, e ne visualizza il risultato.

 NB: non usare la funzione sqrt!
*/

int rad(int, int*);

int main(void){
    int a, radiceIntera, x;
    scanf("%d", &a);
    x = rad(a, &radiceIntera);
    printf("radice: %d, exit code: %d\n", radiceIntera, x);
    return 0;
}

int rad(int x, int *ris){
    if(x == 1){
        *ris = 1;
        return 1;
    }
    for(int i=1; i<=x; i++){
        if(i*i >= x){
            if(i*i == x){
                *ris = i;
                return 1;
            } else{
                *ris = i-1;
                return 0;
            }
        }
    }
    *ris = 0;
    return 0;
}