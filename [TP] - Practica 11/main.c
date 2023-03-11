#include <stdio.h>
#include <stdlib.h>

#define N 8

typedef struct HORA {
    unsigned hora,minuto,segundo;
}HORA;

typedef struct COMPLEJO {
    float real,imaginaria;
    struct HORA  tiempo;
}COMPLEJO;

typedef struct lista_COMPLEJOS {
    unsigned total;
    struct COMPLEJO lista[N];
}LISTA;


void print_HORA(struct HORA );
void scan_HORA(struct HORA *);
void scan_COMP (struct COMPLEJO *);
void print_COMP(struct COMPLEJO);
void cualquier_tecla();
void inicializar_lista(struct lista_COMPLEJOS *);
void aniadir_COMPLEJO(struct lista_COMPLEJOS *,struct COMPLEJO);
void eliminar_COMPLEJO(struct lista_COMPLEJOS *);
void print_lista_COMPLEJOS(struct lista_COMPLEJOS);

int main() {
    char ans;
    COMPLEJO complejo;
    LISTA lista_complejos;
    inicializar_lista(&lista_complejos);
    do {
        system("cls");
        printf("POSICIONES DE UN MOVIL CON COORDENADAS COMPLEJAS\n1. Addear un numero complejo (8 MAX)\n2. Eliminar last numero complejo\n3. Listar numeros complejos\n0. Exitear\n");
        scanf("%c", &ans);
        switch (ans) {
            case '1':
                scan_COMP(&complejo);
                aniadir_COMPLEJO(&lista_complejos, complejo);
                cualquier_tecla();
                break;
            case '2':
                eliminar_COMPLEJO(&lista_complejos);
                cualquier_tecla();
                break;
            case '3':
                print_lista_COMPLEJOS(lista_complejos);
                cualquier_tecla();
                break;
        }
    }while(ans!='0');
}

void print_HORA(struct HORA hora){
    printf("%u:%u:%u\n\n", hora.hora, hora.minuto, hora.segundo);
}
void scan_HORA(struct HORA *hora){
    printf("Introduzca la hora (en formato 24h): ");
    scanf("%u:%u:%u", &hora->hora, &hora->minuto, &hora->segundo);
}
void scan_COMP (struct COMPLEJO *complejo){

    printf("Introduzca Real: ");
    scanf("%f", &complejo->real);
    printf("Introduzca Imaginario: ");
    scanf("%f", &complejo->imaginaria);
    scan_HORA(&complejo->tiempo);
}
void print_COMP(struct COMPLEJO complejo){
    printf("%f-%f i\n", complejo.real, complejo.imaginaria);
    print_HORA(complejo.tiempo);
}
void cualquier_tecla() {
    printf("Press to continuar. . .");
    getchar();
}
void inicializar_lista(struct lista_COMPLEJOS *complejos){
    complejos->total=0;
}
void aniadir_COMPLEJO(struct lista_COMPLEJOS *lista,struct COMPLEJO complejo){
    if(lista->total<N){
        lista->lista[lista->total++]=complejo;
    }
    else
        printf("Nu uh");
}
void eliminar_COMPLEJO(struct lista_COMPLEJOS *lista){
    lista->total--;
}
void print_lista_COMPLEJOS(struct lista_COMPLEJOS lista){
    int pos;
    for (pos=0; pos<lista.total; pos++){
        print_COMP(lista.lista[pos]);
    }
}