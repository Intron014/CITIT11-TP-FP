#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, min, nex;

    do{
        printf("Introduzca el numero de secuencias: ");
        scanf("%i", &n);
    }while(n<2||n>6);

    printf("\nIntroduzca el primer valor: ");
    scanf("%i", &min);
    do{
        scanf("%i", &nex);
        if(min>nex){
            n--;
            min=nex;
            printf("---Siguiente Cadena (%i restante(s))---\n", n);}
        else
            min=nex;
    }while(n>0);
    printf("No hay mas cadenas que crear");

}
