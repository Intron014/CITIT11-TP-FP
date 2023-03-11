#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1, n2, n3;
    printf("La finalidad de este programa es que te de el numero mas grande de los introducidos \n");
    printf("------------------------------------------------------------------------------------ \n \n \n");
    printf("Introduzca 3 numeros enteros, por favor: ");
    scanf("%d &d %d", &n1, &n2, &n3);
    printf("El numero mas grande es %d", n1>n2?n1>n3?n1:n3:n2>n3);

}
