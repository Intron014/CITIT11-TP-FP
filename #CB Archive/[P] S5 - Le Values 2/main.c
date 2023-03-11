#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    printf("Introduzca un caracter: \n");
    do{
        scanf("%c", &c);
        if((c>='A')&&(c<='Z'))
            printf("PLACEHOLDER 1\n");
        else
            if((c>='a')&&(c<='z'))
            printf("PLACEHOLDER 2\n");
        else
            if((c>='0')&&(c<='9'))
            printf("PLACEHOLDER 3\n");
    }
    while(c!='*');
}
