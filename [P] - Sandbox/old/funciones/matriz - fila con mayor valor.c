#include <stdio.h>

unsigned fila_mayor (int mat [10][15]){
    int max=0, i, j, suma, f_max=0;
    for (j=0;j<15;j++) {
        max+=mat[0][j];
    }
    for (i=1;1<10;i++){
        for (j=0, suma=0;j<15;j++){
            suma+=mat[i][j];
        }
        if(suma>max){
            max=suma;
            f_max=i;
        }
    }
    return(f_max);
}
