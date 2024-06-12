#include<stdio.h>
#define DIM 10
// prototipi
int conta(int *, int);
/*
la funzione conta, che cerca in un array di interi il numero di sequenze (anche composte da un solo valore)
di valori dispari in posizioni adiacenti e restituisce -1 nel caso non esistano valori dispari nell’array. Ad
esempio, se l’array contiene i seguenti valori {3, 5, 4, 6, 7, 6, 4, 1, 1, 7} la funzione conta restituisce il valore
3 .*/
int tuttiminori(int *,int,int, int);
/*La funzione ricorsiva tuttiminori, che riceve in ingresso un array di interi, il numero di elementi
contenuti, un indice della posizione corrente e un ulteriore intero k e verifica che tutti gli elementi dell’array
sono strettamente minori di k. La funzione restituisce 1 se la propriet`a `e verificata, 0 altrimenti*/

int main(){
  int a[]={2,4,3,5,6,7,5,6,6,8};
  int b[]={1,3,5,7,9,1,3,5,7,9};
  int r;
  int i;
  int num;
  
  r=conta(a,DIM);
  printf("Ci sono %d sequenze di valori dispari nell'array\n", r);
  r=conta(b,DIM);
  printf("Ci sono %d sequenze di valori dispari nell'array\n", r);
  printf("\nInserisci un valore: ");
  scanf("%d",&num);
  r=tuttiminori(a,DIM,0,num);
  printf("\nEsito: %d",r);
  
}

//conta le sequenze, anche di un solo elemento, di valori dispari, -1 se non esistono
int conta(int *val,int dim){
  int count=0, check=0, r=0;
	for(int i=0; i<dim; i++){
    if(val[i]%2 == 1){
      check = 1;
      count++;
    } else {
      if(count>1) {
        r++;
      }
      count=0;
    }
    if(i == dim-1 && count >1 && val[i]%2 == 1)
      r++;
  }
  if(!check)
    return -1;
	return r;
}
		
/* 
funzione RICORSIVA: restituisce 1 se tutti gli elementi dell'array sono minori di k, 0 altrimenti
*/	
int tuttiminori(int *a, int dim, int pos,int k){
	if(pos == dim)
    return 1;
  if(*(a+pos)<k)
    return tuttiminori(a, dim, pos+1, k);
  else
    return 0;
}	