#include <stdio.h>
#define N 10
/*
SCOPE DI UN IDENTIFICATORE

coord_t globale
x, y solo all'interno della struttura

F globale

c1, c2 scope locale a main

*/

typedef struct {
    int x, y;
} coord_t;

void F(int x);

int main(void){
    coord_t c1, c2;

    c1.x = 5;

    return 0;
}

void F(int x){
    int n;

}