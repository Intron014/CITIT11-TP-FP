/*Lee chars hasta que haya mas 1's que 0's*/

void main(){
	char c, masc;
	int conta;
	printf("Introduzca Chars");
	do{
		c=getchar();
		for(conta=0,masc=1;masc;masc<<=1={
			if(masc&c){
				conta++;
			}
		}
	}while(conta<5);
	putchar(c);
	impr_bin(c);
}