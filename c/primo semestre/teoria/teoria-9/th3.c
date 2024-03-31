#include <stdio.h>
/*
RECORD ATTIVAZIONE

STACK funziona LIFO - Last In First Out
*/

void a();
void b();
void c();

int main(void){
    
    a();

    return 0;
}

void a (){
    printf("Inizio a\n");
    b();
    printf("Fine a\n");
}

void b (){
    printf("Inizio b\n");
    c();
    printf("Fine b\n");
}
void c (){
    printf("Inizio c\n");
    
    printf("Fine c\n");
}