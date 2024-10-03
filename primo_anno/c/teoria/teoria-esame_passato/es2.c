#include <stdio.h>
#define DIM 25

/*
Completare il programma scrivendo le seguenti funzioni:
• anagramma che date in ingresso due stringhe restituisce 1 se le due stringhe
sono una l’anagramma (gli stessi caratteri ma in posizioni anche diverse) dell’altra, 0 altrimenti.

• dimmianagrammi che riceve in ingresso una stringa contenente un vocabolo restituisce 
il numero di vocaboli presenti nel file di testo dizionario.txt che sono anagrammi della stringa in ingresso. 
I vocaboli presenti nel dizionario sono di al più 25 caratteri, uno per riga. 
Nel caso in cui ci siano problemi di accesso al file, il sottoprogramma restituisce -1.

Per esempio, se il sottoprogramma riceve in ingresso la stringa mira e il file dizionario.txt
 contiene i vocaboli ammira armi mari miramira rami rima la funzione restituisce 4.
*/

/*prototipi delle funzioni*/
int anagramma(char*, char*);
int dimmianagrammi(char*);

int main(){
	char str[DIM+1];
	int num;
	
	scanf("%s",str);
	num=dimmianagrammi(str);
	printf("%d",num);
}


int anagramma(char *s1, char *s2){
    int check, len=0, len2=0;
    for(int i=0; s1[i] != '\0'; i++)
        len++;

    for(int i=0; s2[i] != '\0'; i++)
        len2++;

    if (len != len2)
        return 0;

    for(int i=0; s1[i] != '\0'; i++){
        check = 0;
        for(int z=0; s2[z] != '\0'; z++){
            if(s1[i] == s2[z])
                check=1;
        }
        if (!check){
            return 0;
        }
            
    }
    return 1;
}

int dimmianagrammi(char *str1){
    int count=0;

    FILE *fp = fopen("dizionario.txt", "r");

    if(!fp){
        return -1;
    } 
    
    while(!feof(fp)){
        char letter[DIM+1];
        
        fscanf(fp, "%s", letter);
        if(anagramma(str1, letter)){
            count++;
        }
            
    }
    
    fclose(fp);
    return count;
}