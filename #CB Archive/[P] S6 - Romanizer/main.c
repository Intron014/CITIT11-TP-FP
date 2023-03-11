#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int n;
    do{
        printf("Introduzca un numero del 1 al 9: ");
        scanf("%u", &n);
    }while(n<1&&n>9);
    printf("Correspondencia en romano: ", n);

    switch(n){
        case 1:printf("I\n");
            break;
        case 2:printf("II\n");
            break;
        case 3:printf("III\n");
            break;
        case 4:printf("IV\n");
            break;
        case 5:printf("V\n");
            break;
        case 6:printf("VI\n");
            break;
        case 7:printf("VII\n");
            break;
        case 8:printf("VIII\n");
            break;
        case 9:printf("IX\n");
            break;

    }
}
