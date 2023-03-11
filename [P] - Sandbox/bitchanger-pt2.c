#include <stdio.h>
#include <stdlib.h>
#define N 50

void comb_filas(int matr[N][N], int f1, int f2){
	int i, j;
	for(i=f1;i<=f2;i++){
		for(j=0;j<N;j++){
			matr[i][j]=(matr[i][j]<<8)>>8;
		}
	}
}

 
 