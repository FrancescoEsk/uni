#include <stdio.h>
#include <math.h>
#define MAX_DIM 5

void cambia(int A[][MAX_DIM], int m, int n, int B[][MAX_DIM]);
int Medio(int A[][MAX_DIM], int i, int j, int m, int n);

int main(){ 

  int M1[MAX_DIM][MAX_DIM]={{2,2,0,2,1},{2,2,0,0,1},{1,2,3,1,1},{1,2,0,1,1},{2,1,0,1,0}};
  int M2[MAX_DIM][MAX_DIM];
  int i, j;
  
  cambia(M1, MAX_DIM, MAX_DIM, M2);
  for (i = 0; i < MAX_DIM; i++)
  {
      for (j = 0; j < MAX_DIM; j++)
        printf("%3d", M2[i][j]);
      printf("\n");
  } 
}

// cambia crea la matrice B calcolando per ogni elemento di A il valor medio dei suoi vicini mediante la funzione Medio
void cambia(int A[][MAX_DIM], int m, int n, int B[][MAX_DIM])
{
	for(int i=0; i<n; i++)
    for(int z=0; z<m; z++)
      B[i][z] = Medio(A, i, z, m, n);
  
}

// Medio calcola il valor medio di tutti gli elementi vicini (secondo la definizione nel pdf) a quello in posizione i e j
int Medio(int A[][MAX_DIM], int i, int j, int m, int n)
{
  int a=i, b=j, media=0, count=0;
  for(int i=a-1; i<=a+1; i++){
    for(int z=b-1; z<=b+1; z++){
      if(i>=0 && i<n && z>=0 && z<m){
        media += A[i][z];
        count++;
      }
    }
  }
  return media/count;
}

