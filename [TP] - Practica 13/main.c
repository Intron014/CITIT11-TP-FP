#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
    char nombre[15], apellidos[35], domicilio[40], poblacion[35], cod_post[6], aseguradora[45], matricula[11];
    unsigned anio_matric;
}ASEGURADO;

void company_search(FILE *data) {
    char nombre_compania[45];
    int i;
    printf("\nIntroduce el nombre de la compania: ");
    fflush(stdin);
    gets(nombre_compania);
    for (i=0;nombre_compania[i];i++){
        nombre_compania[i]= toupper(nombre_compania[i]);
    }
    printf("\nListado de conductores asegurados por %s:\n", nombre_compania);
    ASEGURADO conductor;
    while (fread(&conductor, sizeof(ASEGURADO), 1, data)) {
        if (strcmp(conductor.aseguradora, nombre_compania) == 0) {
            printf("%s %s - Matricula: %s - anio matriculacion: %u\nDireccion: %s - %s\n--\n",
                   conductor.nombre, conductor.apellidos, conductor.matricula, conductor.anio_matric, conductor.domicilio, conductor.poblacion);
        }
    }
}

void year_search(FILE *data) {
    unsigned anio;
    printf("\nIntroduce el anio de matriculacion: ");
    scanf("%u", &anio);
    printf("\nListado de conductores matriculados a partir de %u:\n", anio);
    ASEGURADO conductor;
    while (fread(&conductor, sizeof(ASEGURADO), 1, data)) {
        if (conductor.anio_matric >= anio) {
            printf("%s %s - Matricula: %s - anio matriculacion: %u\nDireccion: %s - %s\n--\n",
                   conductor.nombre, conductor.apellidos, conductor.matricula, conductor.anio_matric, conductor.domicilio, conductor.poblacion);
        }
    }
}

void cp_search(FILE *data) {
    char codigo_postal[3];
    printf("\nIntroduce los dos primeros digitos del CP: ");
    scanf("%s", codigo_postal);

    printf("\nListado de conductores asegurados en la provincia con CP %s:\n",codigo_postal);
    ASEGURADO conductor;
    while (fread(&conductor, sizeof(ASEGURADO), 1, data)) {
        if (strncmp(conductor.cod_post, codigo_postal, 2) == 0) {
            printf("%s %s - Matricula: %s - anio matriculacion: %u\nDireccion: %s - %s\n--\n",
                   conductor.nombre, conductor.apellidos, conductor.matricula, conductor.anio_matric, conductor.domicilio, conductor.poblacion);
        }
    }
}

void printer(FILE *data){
    ASEGURADO conductor;
    FILE *output;
    output=fopen("C:\\Users\\me\\Documents\\GitHub\\CITIT11-Programming\\[TP] - Practica 13\\output.txt","w");
    printf("Listado completo de conductores asegurados:\n");
    while(fread(&conductor, sizeof(ASEGURADO), 1, data)){
        /*printf("%s %s - Matricula: %s - anio matriculacion: %u\nDireccion: %s - %s\n--\n",
               conductor.nombre, conductor.apellidos, conductor.matricula, conductor.anio_matric, conductor.domicilio, conductor.poblacion);*/
        fprintf(output, "%s %s - Matricula: %s - anio matriculacion: %u Direccion: %s - %s\n",
                conductor.nombre, conductor.apellidos, conductor.matricula, conductor.anio_matric, conductor.domicilio, conductor.poblacion);
    }
    fclose(output);
}

void pause(){
    fflush(stdin);
    printf("Press a key to continue");
    getchar();
}
int main(int argc, char *argv[]) {
    if(argc<2)
        return(1);
    FILE *data = fopen(argv[1], "rb");
    if (!data) {
        printf("Error al abrir el fichero.\n");
        return 69;
    }
    int opcion = 10;
    do {
        rewind(data);
        system("cls");
        printf("\nMain Menu:\n");
        printf("1. Search by company.\n");
        printf("2. Search by year (and upwards).\n");
        printf("3. Search by postal code (Two first digits).\n");
        printf("4. Print the whole file & Saves it to a .txt\n");
        printf("0. Exit.\n");
        printf("\nMake a selection: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                company_search(data);
                pause();
                break;
            case 2:
                year_search(data);
                pause();
                break;
            case 3:
                cp_search(data);
                pause();
                break;
            case 4:
                printer(data);
                pause();
                break;
            case 0:
                printf("Bye bye!.\n");
                pause();
                fclose(data);
                return 0;
        }
    }while(opcion>=0&&opcion<=4);
}