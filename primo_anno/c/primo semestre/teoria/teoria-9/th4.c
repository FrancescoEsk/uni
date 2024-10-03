#include <stdio.h>
/*
PASSAGGIO PARAMETRI
- PER VALORE
- PER INDIRIZZO
*/

float circonferenza(float);

int main(void){
    float r, c;
    
    c = circonferenza(r);

    return 0;
}

float circonferenza (float raggio){
    float circ;
    circ = raggio * 2 * 3.14;
    raggio = 7; // questa istruzione non ha alcun effetto su r, ma solo su raggio
    return circ;
}