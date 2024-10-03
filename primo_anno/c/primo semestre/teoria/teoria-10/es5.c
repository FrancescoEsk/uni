#include <stdio.h>
/*
calcola la somma di due frazioni rappresentate come strutture
*/

typedef struct {
    int num;
    int den;
} fract;

fract add(fract, fract); // somma due frazioni e la semplifica grazie alla simplify
fract simplify(fract); // semplifica la frazione

int main(void){
    fract f1, f2, sum;
    printf("Inserisci il numeratore della frazione 1: ");
    scanf("%i", &f1.num);
    do{
        printf("Inserisci il denominatore della frazione 1: ");
        scanf("%i", &f1.den);
    } while (f1.den == 0);

    printf("Inserisci il numeratore della frazione 2: ");
    scanf("%i", &f2.num);
    do{
        printf("Inserisci il denominatore della frazione 2: ");
        scanf("%i", &f2.den);
    } while (f2.den == 0);

    sum = add(f1, f2);
    printf("Frazione risultante: %i / %i\n", sum.num, sum.den);
    return 0;
}

fract add(fract f1, fract f2){
    fract f;
    f.den = f1.den * f2.den;
    f.num = (f1.num * f2.den) + (f2.num * f1.den);
    return simplify(f);
}

fract simplify(fract f){
    for (int i=2; i<f.num && i<f.den; i++){
        if (f.num%i == 0 && f.den%i == 0){
            f.num /= i;
            f.den /= i;
            i=2;
        }
    }
    return f;
}