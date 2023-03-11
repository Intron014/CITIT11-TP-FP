#include <stdio.h>
#include <stdlib.h>
#define N 50

unsigned contar_letras(char *cad){
	unsigned contas[26]={0}, 1, cont=0;
	for(;*cad;cad++){
		if(isalpha(*cad))
			contas[tolower(*cad)-'a']++
	}
	for(i=0;i<26;i++){
		if(contas[i])
			cont++;
}