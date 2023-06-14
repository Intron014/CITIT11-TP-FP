// Escribir una funcion que recibiendo como parametros de entrada los dias que tiene un mes y el dia de la semana en que cae el dia 1 imprima el calendario de ese mes

void cal_maker (int m, int s){
    int week;
    printf("Lu Ma Mi Ju Vi Sa Do\n");
    printf("---------------------\n");
    for(week=1;week<s;week++){
        printf("   ");
    }
    for(week=1;week<=m;week++){
        printf("%3d", week);
        if(++s>7){
            s=1;
            printf("\n");
        }
    }
}

int switchometer (char semana){
    switch (semana) {
        case ('L'|'l'):return(1);
        case ('M'|'m'):return(2);
        case ('X'|'x'):return(3);
        case ('J'|'j'):return(4);
        case ('V'|'v'):return(5);
        case ('S'|'s'):return(6);
        case ('D'|'d'):return(7);
    }
}

int main(){
    int m, s;
    char weekchar;
    printf("Cuantos dias tiene el mes?: ");
    fflush(stdin);
    scanf("%i", &m);
    printf("Que dia de la semana empieza?: ");
    fflush(stdin);
    scanf("%c", &weekchar);
    s=switchometer(weekchar);
    cal_maker(m, s);
}