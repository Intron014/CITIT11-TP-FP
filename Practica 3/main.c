#include <stdio.h>

int main()
{
    float n, n2;
    int pos;
    char ans;
    do{
        pos=0;
        printf("Introduzca un numero: ");
        fflush(stdin);
        scanf("%f", &n);
        n2=n-(int)n;
        printf("Ha introducido el numero %f\n", n);
        if(n>1) {
            printf("----Parte Entera (%f)----\n", n - n2);
            while (n >= 1)
                printf("Bit %d: %d \n", pos++, ((n = n / 2) - (int) n) >= 0.5 ? 1 : 0);
        }
        if(n2>0) {
            printf("----Parte Decimal (%f)----\n", n2);
            pos = 0;
            do {
                printf("Bit %i: %i\n", pos++, (n2 *= 2) >= 1 ? 1 : 0);
                n2 = n2 - (int) n2;
            } while (pos <= 23);
        }
        printf("Desea repetir la experiencia inolvidable que es convertir un numero a binario? (y/n)");
        fflush(stdin);
        scanf("%c", &ans);
    } while(ans=='y'||ans=='Y'||ans=='\n');
    printf("Gracias por utilizar el sistema conversion a binario! \nMade by Jorge B. \n\n\n");
}