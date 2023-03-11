#include <stdio.h>

// defines
#define maximo_chars 64


// prototipos
void binario_entera(int, char [maximo_chars]);
// un int se convierte a binario (se almacena en el array)

void binario_fraccionaria(float , char [maximo_chars]);
// un float se convierte a binario (se almacena en el array)

void resetear(char [maximo_chars]);  // se resetea el array

void poner_posicion (char [maximo_chars],int , char );
// se coloca un char en la posicion int del array

int bits_blanco(char [maximo_chars]);
// chars en blanco en el array

void insertar_final(char [maximo_chars],char c);
// se inserta un char al final del array, desplazando el resto a la izquierda

void prn_binario(char [maximo_chars]);
// se printa el array con los char del numero binario


int main()
{
    float n, n2;
    int pos;
    char ans, num[maximo_chars];
    do{
        printf("Introduzca un numero: ");
        fflush(stdin);
        scanf("%f", &n);
        n2=n-(int)n;
        printf("Ha introducido el numero %f\n", n);
        resetear(num);
        binario_entera((int)n, num);
        prn_binario(num);
        printf(".");
        resetear(num);
        binario_fraccionaria(n2, num);
        prn_binario(num);
        // The end and repeat
        printf("\nDesea repetir la experiencia inolvidable que es convertir un numero a binario? (y/n)");
        fflush(stdin);
        scanf("%c", &ans);
    } while(ans=='y'||ans=='Y'||ans=='\n');
    printf("Gracias por utilizar el sistema conversion a binario! \nMade by Jorge B. \n\n\n");
}


// definicion de las funciones

void binario_entera(int n, char array[maximo_chars]){
    int pos;
        for(pos=maximo_chars-1;n>=1;pos--, n=n/2)
            array[pos] = n%2? '1' : '0';
}
void binario_fraccionaria(float n2, char array[maximo_chars]){
    int pos;
    if(n2>0) {
        for(pos=0;pos<=23;pos++){
            array[pos]=(n2 *= 2) >= 1 ? '1' : '0';
            n2 = n2 - (int) n2;
        }
    }
}
void resetear(char reset[maximo_chars]){
    int pos;
    for(pos=0;pos<=maximo_chars;pos++){
        reset[pos]=' ';
    }
}
void poner_posicion(char pos[maximo_chars],int n, char r){
    pos[n] = r;
}
int bits_blanco(char white[maximo_chars]){
    int pos, contador;

    for (pos = 0, contador = 0; pos < maximo_chars; pos++)
        if (white[pos] == ' ')
            contador++;

    return contador;
}
void insertar_final(char ins[maximo_chars],char c){
    int pos;

    for (pos = 0; pos < maximo_chars - 1; pos++)
        ins[pos] = ins[pos + 1];

    ins[pos] = c;
}
void prn_binario(char printing[maximo_chars]){
    int pos;
    for(pos=0;pos<maximo_chars;pos++){
        if(printing[pos]!=' '){
            printf("%c",printing[pos]);
        }
    }
}
