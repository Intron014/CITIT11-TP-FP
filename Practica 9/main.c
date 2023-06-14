#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 25

void rellenar (char *);
void eliminar (char *, char *);
int pos_car_fin (char *, char);
int random_number(int low, int max)
{
    int result = 0;
    result = (rand() % (max - low)) + low;
    return result;
}

int main(){
    srand(time(NULL));
    int a;
    char arraya[N], arrayb[N], c;
    printf("\nFuncion 1:\n----\n");
    rellenar(arraya);
    rellenar(arrayb);
    printf("\n\nFuncion 2:\n----\n");
    eliminar(arraya, arrayb);
    printf("\n\nFuncion 3:\n----\nIntroduzca un caracter (Array B): ");
    fflush(stdin);
    scanf("%c", &c);
    pos_car_fin(&arrayb, c);
}

//Almacenar caracteres alfanumericos generados aleatoriamente
void rellenar (char *array){
    int length, pos;
    char rnd;
    length= random_number(0, 23);
    for(pos=0; pos<=length; pos++){
        rnd= random_number(0,2);
        if(rnd==0){
            rnd=random_number(65, 90);
            array[pos]=rnd;
        }
        if(rnd==1){
            rnd=random_number(97, 122);
            array[pos]=rnd;
        }
        if(rnd==2){
            rnd=random_number(49,57);
            array[pos]=rnd;
        }
    }
    array[pos]='\0';
    printf("%s\n", array);
}

void eliminar (char *array1, char *array2){
    int i;
    for(i = 0; array1[i]; )
        if (strchr(array2, array1[i]))
            strcpy(array1+i, array1+i+1);
        else
            i++;

    puts(array1);
}

int pos_car_fin (char *array, char c){
    int pos1, pos2=0;
    pos1=strlen(array);
    while(array[pos1]!=c){
        pos1--;
        pos2++;
    }
    if(pos1<0)
        printf("%d", pos1);
    else
    printf("El caracter %c esta en %d", c, pos2);
}
