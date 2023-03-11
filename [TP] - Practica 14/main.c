#include <stdio.h>
#include <string.h>

typedef struct{
    char nombre[15], apellidos[35], domicilio[40],
  poblacion[35], cod_post[6], aseguradora[45],
  matricula[11];
    unsigned anio_matric;
} ASEGURADO;

int main() {
    ASEGURADO conductores;
    char fichero1[50], fichero2[50], fichero3[50], aux[50], aux2[50];
    int i;
    //Pt1
    printf("Introduzca nombre del fichero a encriptar: ");
    scanf("%s", fichero1);
    //Pt2
    FILE *f1;
    if(!(f1=fopen(fichero1, "rb"))){
        printf("Error al abrir el fichero");
        return 1;
    }
    //Pt3
    strcpy(fichero2, fichero1);
    char *pto=strstr(fichero2, ".");
    *pto='\0';
    strcpy(aux, pto+1);
    strcat(fichero2, "-1.");
    strcat(fichero2, aux);
    //Pt4
    FILE *f2;
    if(!(f2= fopen(fichero2, "wb"))){
        printf("Error al abrir el fichero");
        fclose(f1);
        return 2;
    }
    strcpy(fichero3, fichero1);
    char *pto2=strstr(fichero3, ".");
    *pto2='\0';
    strcpy(aux2, pto+1);
    strcat(fichero3, "-2.");
    strcat(fichero3, aux);
    FILE *f3;
    if(!(f3= fopen(fichero3, "wb"))){
        printf("Error al abrir el fichero");
        fclose(f1);
        fclose(f2);
        return 3;
    }
    //Pt5
    char mask=fichero2[0];
    unsigned maskanio=mask;
    for(i=0;i<3;i++){
        maskanio<<=8;
        maskanio |= mask;
    }
    //Pt6
    while (fread(&conductores, sizeof(ASEGURADO), 1, f1)) {
        for (i=0; conductores.nombre[i]; i++){
            conductores.nombre[i] ^= mask;
        }
        for (i=0; conductores.apellidos[i]; i++){
            conductores.apellidos[i] ^= mask;
        }
        for (i=0; conductores.domicilio[i]; i++){
            conductores.domicilio[i] ^= mask;
        }
        for (i=0; conductores.poblacion[i]; i++){
            conductores.poblacion[i] ^= mask;
        }
        for (i=0; conductores.cod_post[i]; i++){
            conductores.cod_post[i] ^= mask;
        }
        for (i=0; conductores.aseguradora[i]; i++){
            conductores.aseguradora[i] ^=mask;
        }
        for (i=0; conductores.matricula[i]; i++) {
            conductores.matricula[i] ^= mask;
        }
        conductores.anio_matric ^= maskanio;

        fwrite(&conductores, sizeof(ASEGURADO), 1, f2);
    }
    fclose(f1);
    fclose(f2);
    if(!(f2= fopen(fichero2, "rb"))){
        printf("Error al abrir el fichero");
        fclose(f1);
        fclose(f3);
        return 4;
    }
    while (fread(&conductores, sizeof(ASEGURADO), 1, f1)){
        printf("%s %s - Matricula: %s - anio matriculacion: %u\nDireccion: %s - %s\n--\n",
               conductores.nombre, conductores.apellidos, conductores.matricula, conductores.anio_matric, conductores.domicilio, conductores.poblacion);
    }
    rewind(f2);
    while (fread(&conductores, sizeof(ASEGURADO), 1, f1) == 1) {
        for (i=0; conductores.nombre[i]; i++){
            conductores.nombre[i] ^= mask;
        }
        for (i=0; conductores.apellidos[i]; i++){
            conductores.apellidos[i] ^= mask;
        }
        for (i=0; conductores.domicilio[i]; i++){
            conductores.domicilio[i] ^= mask;
        }
        for (i=0; conductores.poblacion[i]; i++){
            conductores.poblacion[i] ^= mask;
        }
        for (i=0; conductores.cod_post[i]; i++){
            conductores.cod_post[i] ^= mask;
        }
        for (i=0; conductores.aseguradora[i]; i++){
            conductores.aseguradora[i] ^=mask;
        }
        for (i=0; conductores.matricula[i]; i++){
            conductores.matricula[i] ^=mask;
        }
        conductores.anio_matric ^= maskanio;
        fwrite(&conductores, sizeof(ASEGURADO), 1, f3);
        printf("%s %s - Matricula: %s - anio matriculacion: %u\nDireccion: %s - %s\n--\n",
               conductores.nombre, conductores.apellidos, conductores.matricula, conductores.anio_matric, conductores.domicilio, conductores.poblacion);
    }
    fclose(f2);
    fclose(f3);
}
