#include <stdio.h>
int main() {
    float p0;
    printf("Introduzca precio del articulo: ");
    scanf("%f", &p0);
        if (p0<=10) {
            printf("El articulo no tiene descuento, total: %f", p0);}
        if ((10.01<=p0)&&(p0<=100)){
            p0=p0*0.90;
            printf("0.1 de descuento aplicado, total: %f", p0);}
        if (p0>100){
            p0=p0*0.75;
            printf("Vd. gasta mucho money, 0.25 descuento aplicado, precio: %f", p0);}

    printf("\nGracias por comprar en UPM-Market, pase un buen dia");

    }
