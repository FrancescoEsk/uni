#include <stdio.h>
/*
scrivere un prog c che definisce un tipo di dato strutturato per rappresentare le frazioni n, d (interi)

scrivere un sottoprog che riceve come param una frazione (passato per riferimento), chiede all'utente
il num e il den e li salva nella variabile ricevuta come param

scrivere un sottoprog che riceve come param una frazione e la semplifica
*/

typedef struct 
{
    int n, d;
} frazione;

void read(frazione*);
void simplify(frazione*);
void print(frazione*);

int main(void){
    frazione a;
    read(&a);
    simplify(&a);
    print(&a);
    return 0;
}

void print(frazione *f){
    printf("%d / %d\n", f->n, f->d);
}

void read(frazione *f){
    scanf("%d", &f->n);
    do{
        scanf("%d", &f->d);
    } while(f->d == 0); // controllo che non sia fratto 0
}

void simplify(frazione *f){
    for(int i=2; i<=(f->n/2) || i<=(f->d/2); i++){ // ciclo da 2 fino alla metà compresa del maggiore dei due
        if(f->n % i == 0 && f->d % i == 0){ // se entrambi sono divisibili, divido
            f->n /= i;
            f->d /= i;
            i--; // se ho diviso, devo ricontrollare se la frazione è nuovamente divisibile per quel numero
        }
    }
}