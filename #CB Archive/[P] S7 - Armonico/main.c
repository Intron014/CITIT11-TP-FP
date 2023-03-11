#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned n, k;
    do{
        printf("Introducir digito: ");
        scanf("%u", &n);
    }while(n==0);

    for(k=1;k<n;k++)
        printf("1/%u, ", k);
    printf("1/%u", n);

}
