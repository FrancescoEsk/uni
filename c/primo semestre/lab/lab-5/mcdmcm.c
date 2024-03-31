#include <stdio.h>
/*
Scrivere un programma che calcoli il massimo comun 
divisore e il minimo comune multiplo di due numeri inseriti 
dall’utente. Entrambi i numeri inseriti devono essere 
maggiori di zero
*/

int main(void){
    int a, b, mcd=0, mcm, mcmX, mcmY, m, x=1, y=1;
    do{
        printf("Inserisci a: ");
        scanf("%i", &a);
        printf("Inserisci b: ");
        scanf("%i", &b);
    } while(a<=0 || b<=0);

    if (a!= 1 && b!= 1){

        if (a>=b)
            m = a;
        else m=b;

        for (int i=2; i<m ;i++){ // massimo comun divisore
            if (a%i == 0 && b%i == 0)
                mcd = i;
        }

        if (mcd!=0)
            printf("\nIl massimo comun divisore di %i e %i e': %i\n", a, b, mcd);
        else
            printf("\nNon esiste un massimo comun divisore tra %i e %i\n", a, b);

        for (int i=a*b; i>1; i--){
            for (int z=1; z<a*i; z++){
                if (b*z == a*i){
                    mcm = a*i;
                    mcmX = i;
                    mcmY = z;
                }

            }
        }

        printf("\nIl minimo comune multiplo di %i e %i e': %i (%i * %i e %i * %i)\n", a, b, mcm, mcmX, a, mcmY, b);
    } else {
        printf("\nIl massimo comun divisore di %i e %i e': 1\n", a, b);
        printf("\nIl minimo comune multiplo di %i e %i e': 1 (1 * %i e 1 * %i)\n", a, b, a, b);
    }
    return 0;
}