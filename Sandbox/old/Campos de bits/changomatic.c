/*Escribir una función que, recibiendo como parámetro una cadena de caracteres, 
cambie a cada carácter de la misma los bits que ocupan posiciones pares*/

typedef struct{
	int bo:1;
	int   :1;
	int b2:1;
	int   :1;
	int b4:1;
	int   :1;
	int b6:1;
	int   :1;
}BYTE;

typedef union{
	char c;
	BYTE byte;
}CAR_BYTE;

void modif_cad (char *cad){
	CAR_BYTE aux;
	for(;*cad;cad++){
		aux.c=*cad;
		aux.byte.b0=aux.byte.b0?0:1;
		aux.byte.b2=aux.byte.b2?0:1;
		aux.byte.b4=aux.byte.b4?0:1;
		aux.byte.b6=aux.byte.b6?0:1;
		*cad=aux.c;
	}
}