#include <stdio.h>

int main() {
    int r, b, e, pos, posbin;
    float bin;
    char ans;
    do {
        do {
            do {
                printf("Introduzca la base [2-10]: ");
                fflush(stdin);
                scanf("%i", &b);
            } while (b < 2 || b > 10);
            do {
                printf("Introduzca el exponente [0-10]: ");
                fflush(stdin);
                scanf("%i", &e);
            } while (e < 0 || e > 10);
            printf("Datos Introducidos:\nBase: %i\nExponente: %i\nSon estos datos correctos? (y/n)\n", b, e);
            fflush(stdin);
            scanf("%c", &ans);
        } while (ans == 'N' || ans == 'n');

        if (e == 0) {
            printf("Base: %i\nExponente: %i\nDecimal: 1\n---\n", b, e);
            printf("Bit 0: 1\n");
            printf("---\n");
        } else {
            for (pos = 1, r = 1; pos <= e; pos++) {
                printf("Base: %i\nExponente: %i\nDecimal: %i\n---\n", b, pos, r *= b);
                posbin = 0;
                bin = r;
                while (bin >= 1)
                    printf("Bit %d: %d \n", posbin++, ((bin=bin / 2) - (int) bin) >= 0.5 ? 1 : 0);
                printf("---\nPULSE CUALQUIER TECLA PARA CONTINUAR\n");
                fflush(stdin);
                scanf("%c", &ans);

            }
        }
        printf("Desea repetir?(y/n)");
        fflush(stdin);
        scanf("%c", &ans);
    }while(ans=='y'||ans=='Y'||ans=='\n');
}
