#include<stdio.h>
#include<string.h>
#define DIM 25

/*prototipi delle funzioni*/
int parola_valida(char*,int);
int conta_valide(int);

int main(){
	int n;
	int num;
	scanf("%d",&n);
	while(n<=0)
		scanf("%d",&n);
	num=conta_valide(n);
	printf("%d\n",num);

}


int parola_valida(char *s1, int n){
    int len=-1;
    for(int i=0; s1[i] != '\0'; i++) len++;
    
    if(len%n != 0)  return 0;
    int check = len/n;

    for(int i=0; s1[i+check] != '\0' && s1[i+check] != '\n'; i++)
        if(s1[i] != s1[i+check])    return 0;
        
    return 1;
}

int conta_valide(int n){
	FILE *fp = fopen("origine.txt", "r");

    if(fp == NULL) return -1;
    int count=0;
    char str[DIM];
    while(fgets(str, DIM, fp) != NULL){
        count += parola_valida(str, n);
    }

    fclose(fp);
    return count;
}
