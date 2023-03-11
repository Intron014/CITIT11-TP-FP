#include <stdio.h>

int main(){
    int master[3][3];
    int array[9];
    int f, c, pos=0, aux2;

    printf("Fill array");

    for(c=0;c<=2;c++, pos++){
        for(f=2; f>0;f--, pos++){
            array[pos]=master[f][c];
        }
        array[pos]=master[f][c];
    }
    for(c=0;c<=1;c++, pos++){
        for(f=2; f>0;f--, pos++){
            array[pos]=master[f][c];
        }
        array[pos]=master[f][c];
    }
    for(c=0;c<=0;c++, pos++){
        for(f=2; f>0;f--, pos++){
            array[pos]=master[f][c];
        }
        array[pos]=master[f][c];
    }

    for(pos=0;pos<9;pos++)
        printf("%i", array[pos]);
}