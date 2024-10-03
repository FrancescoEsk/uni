#include <stdio.h>
#define DIM 100

/*
Scrivere un programma C che richiede all'utente due
stringhe a e b, e determina se b é contenuta in a.
Suggerimento:
Determinare l'inizio di b in a: cercare la posizione i in a del
primo carattere di b.
Se a non contiene il primo carattere di b, allora sicuramente b
non é contenuta in a.
Altrimenti procedere dalla posizione i in a e controllare
l'uguaglianza con gli altri caratteri di b, finché non si raggiunge la
fine di una delle due stringhe o si trovano due caratteri diversi.
Se si raggiunge la fine di b, allora tutta la stringa b é
contenuta in a. Se si raggiunge la fine di a senza raggiungere la
fine di b, allora b non é contenuta in a.
Altrimenti si riprende dalla posizione i + 1 e si cerca ancora la
posizione del primo carattere di b.
*/

int main() {
    char str1[DIM+1], str2[DIM+1];
    scanf("%s", str1);
    scanf("%s", str2);
    int check=1;
    for(int i=0; i<DIM+1 && str2[i]!='\0'; i++){
        check = 0;
        for (int k=0; k<DIM+1 && str1[k]!='\0'; k++){
            if (str2[i]==str1[k]){
                check=1;
            }
        }
        
    }
    if (check==0)
        printf("la stringa b non è contenuta in a\n");
    else
        printf("La stringa b è contenuta in a\n");
	return 0;

}
