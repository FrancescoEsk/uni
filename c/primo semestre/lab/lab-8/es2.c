#include <stdio.h>

/*
Scrivere un programma C che chiede all'utente le
coordinate di due punti a e b appartenenti al piano
cartesiano e disegna il perimetro del rettangolo con i lati
paralleli agli assi che ha il segmento ab come diagonale. Le
coordinate di a e b devono essere intere e comprese tra 0 e
9. Usare strutture per definire “punto” e “rettangolo”.
Suggerimento: usare una matrice per aiutarsi a stampare. L’Output dovrebbe essere ad esempio:
Punto a
Inserire l'ascissa (valore compreso tra 0 e 9): 3
Inserire l'ordinata (valore compreso tra 0 e 9): 6
Punto b
Inserire l'ascissa (valore compreso tra 0 e 9): 5
Inserire l'ordinata (valore compreso tra 0 e 9): 2
9
8
7
6 * * *
5 * *
4 * *
3 * *
2 * * *
1
0
0 1 2 3 4 5 6 7 8 9
*/
struct p {
    int x;
    int y;
};

int main(void){
    struct p a, b;
    printf("Punto a\n");
    do{
        printf("Inserire l'ascissa (valore compreso tra 0 e 9): ");
        scanf("%i", &a.x);
        printf("Inserire l'ordinata (valore compreso tra 0 e 9): ");
        scanf("%i", &a.y);
    } while (a.x < 0 || a.x > 9 || a.y < 0 || a.y > 9);
    printf("Punto b\n");
    do{
        printf("Inserire l'ascissa (valore compreso tra 0 e 9): ");
        scanf("%i", &b.x);
        printf("Inserire l'ordinata (valore compreso tra 0 e 9): ");
        scanf("%i", &b.y);
    } while (b.y < 0 || b.y > 9 || b.x < 0 || b.x > 9);
    
    for (int i=9; i>=-1; i--){
        if (i!=-1)  printf("%i", i);
        else printf("  ");
    
        for (int z=0; z<9; z++){
            if(i == -1) printf("%i", z+1);
            else{
                if ((i==a.y || i == b.y) && (z>=a.x && z<=b.x) || (z==a.x || z == b.x) && (i>= b.y && i<=a.y)){
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
