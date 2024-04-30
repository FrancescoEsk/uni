#include <stdio.h>
/*
VARIABILI LOCALI
    AUTOMATICHE : quando viene creata ogni volta che si invoca una funzione
    --> creata sullo stack

    STATICHE : create una sola volta all'avvio del programma principale
    static int a;
    --> quando la funzione termina, la var statica MANTIENE il proprio valore 
        per le prossime invocazioni della funzione
!!! --> valore di default = 0 !!!

ESEMPIO
*/

void f(){
    int a=1; // var locale automatica
    static int b=1; // var locale statica

    printf("Variabile automatica: %d, Variabile statica: %d\n", a, b);
    a++; // ad ogni invocazione, la variabile muore e rinasce. RIMANE SEMPRE 1
    
    b++; // ad ogni invocazione, la variabile cresce
}

int main(void){
    for (int i=0; i<10; i++)
        f();
    return 0;
}