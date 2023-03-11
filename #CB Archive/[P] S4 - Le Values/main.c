#include <stdio.h>
#include <stdlib.h>

int main()
{
    int min, max, temp;
    printf("Introduzca un valor: ");
    scanf("%d", &temp);
    fflush(stdin);
    max=min=temp;

    printf("Introduzca un valor: ");
    scanf("&d", &temp);
    fflush(stdin);
    while(temp)
    {
        if(temp>max)
            max=temp;
            else
            if (temp<min)
                min=temp;
        printf("Introduzca un valor: ");
        scanf("%d", &temp);
        fflush(stdin);

    }
    printf("Valor minimo %d y valor maximo %d", min, max);
}
