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
//-----------------------------------------------------------------------------
// prototipos a definir en esta práctica
void mover_izda(char [maximo_chars]);
// mueve a la izda todos los bits del array

void scan_real(float *);
// scan del número real a convertir

int posicion_punto_decimal (char [maximo_chars]);
// posicion en el array de ‘.’

void notacion_cientifica(char [maximo_chars], int * );
// convierte el binario en notacion cientifica, transmitiendo el exponente

void copiar_mantisa(char [maximo_chars],char [32]);
// copia la mantisa a un array de 32 chars, en las últimos 23 posiciones del array

void copiar_exponente(char [maximo_chars],char r[32]);
// copia el exponente a un array de 32 chars, en las 8 siguientes posiciones a la posicion 0

void colocar_signo(char ,char [32]);
// coloca el signo en un array de 32 chars, en la posicion 0

//-------------------------------------------------------------------------------


int main()
{
    float n;
    int pos, exp;
    char ans, num[maximo_chars], array[maximo_chars];
    do{
        scan_real(&n);
        resetear(num);
        resetear(array);
        printf("Representacion binaria: ");
        binario_entera((int)n, num);
        prn_binario(num);
        binario_fraccionaria(n-(int)n, num);
        prn_binario(num);
        printf("\n");
        /*for(pos=0;pos<maximo_chars;pos++){
            printf("%c", array[pos]);
        }
        notacion_cientifica(num, &exp);*/
        // The end and repeat
        printf("\nDesea repetir la experiencia inolvidable que es convertir un numero a binario? (y/n)");
        fflush(stdin);
        scanf("%c", &ans);
    } while(ans=='y'||ans=='Y'||ans=='\n');
    printf("Gracias por utilizar el sistema conversion a binario! \nMade by Jorge B. \n\n\n");
}


// definicion de las funciones

void binario_entera(int n, char array[maximo_chars]){
    int pos=maximo_chars-1;
    //array[pos]='.';
    for(pos=maximo_chars-2;n>=1;pos--, n=n/2)
        array[pos] = n%2? '1' : '0';
    insertar_final(array, '.');
}
void binario_fraccionaria(float n2, char array[maximo_chars]){
    int pos;
    if(n2>0) {
        for(pos=0;pos<=23;pos++){
            insertar_final(array, (n2 *= 2) >= 1 ? '1' : '0');
            n2 = n2 - (int) n2;
        }
    }
}
void mover_izda(char arrey[maximo_chars]){
    int pos;
    for(pos=0; pos<maximo_chars-1; pos++){
        arrey[pos]=arrey[pos+1];
    }
}
void resetear(char reset[maximo_chars]){
    int pos;
    for(pos=0;pos<maximo_chars;pos++){
        reset[pos]=' ';
    }
}
void poner_posicion(char pos[maximo_chars],int n, char r){

}
int bits_blanco(char white[maximo_chars]){
    int pos, spaces;
    for(pos=0;pos<=maximo_chars;pos++){
        if(white[pos]==' '){
            spaces++;
        }
    }
    return(spaces);
}
void insertar_final(char ins[maximo_chars],char c){
    mover_izda(ins);
    ins[maximo_chars-1]=c;
}
void prn_binario(char printing[maximo_chars]){
    int pos;
    for(pos=0;pos<maximo_chars;pos++){
        if(printing[pos]!=' '){
            printf("%c",printing[pos]);
        }
    }
}

void scan_real(float *n){
    printf("Introduzca un numero: ");
    fflush(stdin);
    scanf("%f", n);
    printf("Numero real en base decimal: %f\n", *n);
}


int posicion_punto_decimal (char array[maximo_chars]){
    int pos;
    for(pos=0; array[pos]!='0'||array[pos]!='1';pos++){
    }
    return (pos);
}

void notacion_cientifica(char science[maximo_chars], int *exp){
    int punto;
    punto=posicion_punto_decimal(science);
    printf("punto %i", punto);

}