#include <stdio.h>
#include <string.h>

char * join(char *cad1, char *cad2){
	int i, j;
	char result[50], aux;
	strcpy(result, cad1);
	strcat(result, cad2);
	for(i=strlen(result)-1;i;i--)
		for(j=0;j<i;j++)
			if(result[j]<result[j+1]{
				aux=result[j];
				result[j]=result[j+1];
				result[j+1]=aux;
			}
	return(result);
}