#include <stdio.h>
/*
Determina se x e' rightprime
ovvero

1 - x è primo
2 - tutti i numeri ottenuti dividendo ripetutamente per 10 sono primi
*/

int primo(int);
int rightprime(int);

int main(void){
    int x;
    printf("Inserisci un numero: ");
    scanf("%i", &x);
    if (rightprime(x) == 1)
        printf("Il numero inserito e' rightprime\n");
    else
        printf("Il numero inserito non e' rightprime\n");
    return 0;
}

int primo(int a){
    for(int i=2; i<=a/2; i++)
        if (a%i == 0)
            return 0;
    return 1;
}

int rightprime(int a){
    if (primo(a) == 1){
        while (a>1){
            a /= 10;
            if (primo(a) == 0)
                return 0;
        }
        return 1;
    }
    return 0;
}