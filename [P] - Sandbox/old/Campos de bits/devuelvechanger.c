/*Escribir una función que, recibiendo como parámetros
un entero, lo devulelva tras poner sus 4 bits centrales a 0*/

int bits_a_cero(int n){
	return(n&~(15<<14));
}