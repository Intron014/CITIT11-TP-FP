#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// defines
#define maximo_chars 64
#define B 4


// prototipos de las funciones que se deben definir en esta práctica

unsigned longitud(unsigned n);  // función recursiva
// longitud(543)=3

float random_real(float *, float *);
// devuelve un número real, calculado aleatoriamente

float real_binario(float real);
// convierte un numero real en base decimal a base binaria, printando el binario

float numero_real(char b[maximo_chars]);
// devuelve en base 10 el numero real correspondiente a un binario con parte entera y fraccionaria

float binario_fraccionaria(float );
float binario_entera(int );

int main(){
    srand(time(NULL));
    float rt, r1=0, r2=0;
    int tr1, tr2;
    long double b1, b2;
    char ans;
    do {
        system("cls");
        random_real(&r1, &r2);
        rt=r1+r2;
        printf("\nNumero Generado: %f\nNumero Binario: ", rt);
        real_binario(r1);
        printf(".");
        real_binario(r2);
        printf("\n%i", tr1);
        printf("\nNumero Decimal Recalculado: %f", r1+r2);
        printf("\nAgain? (y/n)");
        fflush(stdin);
        scanf("%c", &ans);
    }while(ans=='\n'||ans==('y')||ans==('Y'));
}

float random_real(float *r1, float *r2){
    *r1 =(rand() % 100000 + 1);
    *r2 =(rand() % 100000 + 1);
    *r2/=100000;
}
float real_binario(float real){
    if(real>=1){
        binario_entera((int)real);
    }
    if(real<1){
        binario_fraccionaria(real);
    }
}
float binario_entera(int n){

    for(;n>=1; n=n/2)
        printf("%c", n%2? '1' : '0');
}
float binario_fraccionaria(float n2){
    int pos=0;
    do {
        printf("%i", (n2 *= 2) >= 1 ? 1 : 0);
        pos++;
        n2 = n2 - (int) n2;
    } while (pos <= 23);
}
unsigned longitud(unsigned n){
    if(n<10)
        return(1);
    else
        return(1+ longitud(n/10));
}