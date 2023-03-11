#include <stdio.h>

int main() {
    char l1, l2, l3;
    printf("Introduzca las letras rango: ");
    scanf("%c %c", &l1, &l2);
    fflush(stdin);
    printf("Introduzca la letra a buscar: ");
    scanf("%c", &l3);

    if ((l3>=l1)&&(l3<=l2))
        printf("La letra %c se encuentra entre la %c y la %c. Felicidades!", l3, l1, l2);
    else
        printf("Muy a mi pesar, la letra %c no esta entre la %c ni la %c", l3, l1, l2);
    }

