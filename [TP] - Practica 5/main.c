#include <stdio.h>

//Prototipos

int scan(int*, int*);
void  potencia(int ,int );
void print_binario(int );
void pulsar();

//Main
int main() {
    int base, exp;
    char ans;
    do {
        system("cls");
        do {
            system("cls");
            scan(&base,&exp);
            printf("Datos Introducidos:\nBase: %i\nExponente: %i\nSon estos datos correctos? (y/n)\n", base, exp);
            fflush(stdin);
            scanf("%c", &ans);
        } while (ans == 'N' || ans == 'n');
        potencia(base, exp);
        printf("Desea repetir?(y/n)");
        fflush(stdin);
        scanf("%c", &ans);
    }while(ans=='y'||ans=='Y'||ans=='\n');
}

//Funcion

int scan(int*b, int*e){
    do {
        printf("Introduzca la base [2-10]: ");
        fflush(stdin);
        scanf("%i", b);
    } while (*b < 2 || *b > 10);
    do {
        printf("Introduzca el exponente [0-10]: ");
        fflush(stdin);
        scanf("%i", e);
    } while (*e < 0 || *e > 10);
}

void potencia (int b, int e){
    int pos, r;
    system("cls");
    if (e == 0) {
        printf("Base: %i\nExponente: %i\nDecimal: 1\n---\n", b, pos);
        printf("Bit 0: 1\n");
        printf("---\n");
    } else {
        for (pos = 1, r = 1; pos <= e; pos++) {
            system("cls");
            printf("Base: %i\nExponente: %i\nDecimal: %i\n---\n", b, pos, r *= b);
            print_binario(r);
            pulsar();
        }
    }
}

void print_binario (int r){
    int posbin=0;
    float bin;
    bin=r;
    while (bin >= 1)
        printf("Bit %d: %d \n", posbin++, ((bin=bin / 2) - (int) bin) >= 0.5 ? 1 : 0);
}

void pulsar(){
    printf("---\nPULSE CUALQUIER TECLA PARA CONTINUAR\n");
    getchar();
}