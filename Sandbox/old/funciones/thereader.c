#include <stdio.h>
#include <string.h>

int main(){
	int i, contar[26], max=0, letras;
	char mayor[101]="", aux[101];
	printf("Introduzca cositas\n-----\n");
	do{
		gets(aux);
		if(aux[0]){
			for(i=0;i<26;i++)
				contas[i]=0;
			for(i=0;aux[i];i++)
				if(isalpha(aux[i])
					contar[toupper(aux[i]-'A']++;
			for(i=0,letras=0;i<26;i++)
				if(contas[i])
					letras++
			if(letras>max){
				max=letras;
				strcpy(mayor, aux);
			}
		}
	}while(aux[0]);
	puts(mayor);
}