#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 50

typedef struct elem{
	int suma;
	float media;
	struct elem * sig;
}NODO;

typedef NODO * LISTA;

void proc_matrices(FILE *f_in, LISTA *l){
	int matriz[N][N], i, j, suma;
	LISTA aux;
	
	while(fread(matriz, sizeof(matriz), 1, f_in)){
		for(suma=0, i=0;i<N;i++){
			for(j=0;j<N;j++){
				suma+=matriz[i][j]
			}
		}
	aux=(LISTA)malloc(sizeof(NODO));
	aux->suma=suma;
	aux->media=(float)suma/(N*N);
	aux->sig=*l;
	*l=aux;
	}
}