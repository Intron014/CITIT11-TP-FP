#include <stdio.h>
#include <string.h>

void main(){
    float aux;
    int num, rest;
    int binary[9]={'0'};
    int binaryordered[9]={'0'};
    do{
        printf("Introduzca el numero a convertir a binario: ");
        scanf("%i", &num);
    }while(num<0||num>256);

    int bit = 0;
    while(num>=1){
        aux=num;
        aux=(aux/2);
        num=(int)aux;
        aux=aux-(int)aux;

        if(aux>=0.5){
            rest=1;
            printf("Bit %i: %i", bit, rest);
        }
        else{
            rest=0;
            printf("Bit %i: %i", bit, rest);
        }
        binary[bit]=rest;
        bit++;
        printf("\n");
    }
    int j=0;
    for(bit = 8; bit >=0; bit--){
        binaryordered[j]=binary[bit];
        j++;
    }
    for(bit=0; bit<9; bit++){
        printf("%i", binaryordered[bit]);
    }
}