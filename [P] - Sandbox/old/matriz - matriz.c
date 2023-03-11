#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define F 10
#define C 15


int main(){
    int matriz[F][C], i, j, fil, col;
    srand(time(NULL));
    for(i=0;i<F;i++)
        for(j=0;j<C;j++)
            matriz[i][j]=rand();
    fil=rand()%(F-1)+1;
    col=rand()%(C-1)+1;
    for(;fil<F;fil++){
        for(j=col;j<C;j++)
            printf("%d ", matriz[fil][j]);
        printf("\n");
    }
}