#include<stdio.h>
#define N 5

//prototipi
int calcola(int matr[N][N]);


int main(){
  int i, j, maxj;
  int m[N][N]={{2,5,10,15,18},{11,7,7,20,15},{5,5,7,11,22},{6,1,3,16,19},{7,1,2,10,18}}; 
  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++)
      printf("%3d", m[i][j]);
	printf("\n");
  }
  maxj = calcola(m);
  printf("\nIndice: %d\n", maxj);
}

// calcola l'indice di colonna con massima differenza tra due elementi
int calcola(int matr[N][N]){
  int diff=matr[0][0]-matr[1][0], col=0, tmp;
  for(int z=0; z<N; z++){
    for(int i=0; i<N; i++){
      for(int j=i+1; j<N; j++){
        tmp = matr[i][z] - matr[j][z];
        if (tmp<0) tmp = -tmp;
        if( (tmp) > diff ){
          diff = tmp;
          col = z;
        }
      }
    }
  }
  return col;
}