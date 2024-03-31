#include <stdio.h>

/*
Si scriva un programma C che definisce una funzione
int next_prime(int last);
che restituisce il numero primo immediatamente successivo a last.
Si utilizzi inoltre la seguente funzione main() per testarne il funzionamento:
int main( ) {
int number;
int c;
int p = 2;
printf("Quanti numeri primi vuoi stampare? ");
scanf("%d”, &number);
for (c = 0; c < number; c++){
printf("%d\n", p );
p = next_prime( p );
}
}
*/

int next_prime(int);

int main(void){
    int number;
    int c;
    int p = 2;
    printf("Quanti numeri primi vuoi stampare? ");
    scanf("%d", &number);
    for (c = 0; c < number; c++){
        printf("%d\n", p );
        p = next_prime( p );
    }
    return 0;
}

int next_prime(int last){
    int c;
    for (int i=last+1; i>0; i++){
        c = 0;
        for (int z=2; z<=i/2; z++)
            if(i%z == 0)
                c = 1;
        
        if (c==0)
            return i;
    }
    return 0;
}