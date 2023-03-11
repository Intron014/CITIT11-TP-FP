#include <stdio.h>
#include <stdlib.h>

int main()
{
    char v, vc, l;

    do{
        printf("Introduzca una vocal minuscula: ");
        fflush(stdin);
        scanf("%c", &v);
    }while(v!='a'&&v!='e'&&v!='i'&&v!='o'&&v!='u');

    printf("ha introducido: %c\n", v);
    printf("Introduzca caracteres: \n");
    do{
        fflush(stdin);
        scanf("%c", &vc);
    }while(vc!=v-'a'+'A');
    printf("Vocal mayuscula encontrada! :)");
}
