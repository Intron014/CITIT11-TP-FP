#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n;
    int pos;
    char ans;
    do{
        pos=0;
            do{
        printf("Introduzca un numero entre el 0 y el 256: ");
        fflush(stdin);
        scanf("%f", &n);
    } while(n<=0||n>256);
    printf("Ha introducido el numero %f\n", n);
    while(n>=1)
        printf("Bit %d: %d \n", pos++, ((n=n/2)-(int)n>=0.5)?1:0);
    printf("Desea repetir la experiencia inolvidable que es convertir un numero a binario? (y/n)");
    fflush(stdin);
    scanf("%c", &ans);
    } while(ans=='y'||ans=='Y'||ans=='\n');
    printf("Gracias por utilizar el sistema conversion a binario! \nMade by Jorge B. \n\n\n");
}

