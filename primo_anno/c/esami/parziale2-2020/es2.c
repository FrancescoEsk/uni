#include <stdio.h>
#include <stdlib.h>
/*
Si completi il file indicato in modo tale che il seguente programma (riportato nel file stub):
int main() {
print_prime_numbers(20);
printf("\n");
return 0;
}
produca il seguente risultato:
2 3 5 7 11 13 17 19
*/

void print_prime_numbers(int);

int main(void){
    print_prime_numbers(20);
    printf("\n");
    return 0;
}

void print_prime_numbers_ric(int num){ // versione ricorsiva
    if(num <= 1) return;
    if(num >= 2){
        int check=0;
        for(int i=2; i<=(num/2) && !check; i++)
            if (num%i == 0) check=1;
        
        if(!check) printf("%d ", num);
        print_prime_numbers(num-1);
    }
}   

void print_prime_numbers(int num){
    int check;
    for(int n=2; n<=num; n++){
        check = 0;
        for(int i=2; i<=(n/2) && !check; i++)
            if(n%i == 0) check = 1;

        if(!check) printf("%d ", n);
    }   
}