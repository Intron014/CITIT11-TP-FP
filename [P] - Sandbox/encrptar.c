#include <stdio.h>
#include <stdlib.h>
#define N 50

void encripter(char *matr[N]){
	int i, j;
	for(i=0;i<N;i++){
		for(j=0;matr[i][j];j++){
			matr[i][j]^=129;
		}
	}
}