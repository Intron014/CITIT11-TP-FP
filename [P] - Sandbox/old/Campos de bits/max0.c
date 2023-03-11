/*Cadena con mayor 0's*/

char * mas_0(char matr[N][]){
	int max=0, conta, i, j, fila_m=0;
	char masc;
	for(i=0;i<N;i++){
		for(j=0,conta=0;matr[i][j];j++){
			for(masc=1;mascMmasc<<=1){
				if(!(masc&matr[i][j])){
					conta++;
				}
			}
		}
		if(conta>max){
			max=conta;
			fila_m=i;
		}
	}
	return(matr[fila_m]);
}