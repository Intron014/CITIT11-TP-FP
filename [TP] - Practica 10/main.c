#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define matriculations 1500
//
int random_number(int low, int max)
{
    int result = 0;
    result = (rand() % (max - low)) + low;
    return result;
}
void mat_gen(char mat[matriculations][11]) //Genera las matriculas
{
    FILE * file;
    file=fopen("potato.txt", "w");
    int rnd, posf, posc, gens=matriculations;
    printf("Plate Generator %i:\n", gens);
    for(posf=0;posf<matriculations;posf++){
        for(posc=0;posc<11;posc++){
            if(posc==0){
                mat[posf][posc]='E';
            }
            if(posc==1||posc==6){
                mat[posf][posc]='-';
            }
            if(posc>1&&posc<6){
                rnd= random_number(48,57);
                mat[posf][posc]=rnd;
            }
            if(posc>6&&posc<10){
                rnd= random_number(65, 90);
                mat[posf][posc]=rnd;
            }
            if(posc==10){
                mat[posf][posc]='\0';
            }
        }
        fprintf(file, "%s\n", mat[posf]);
        //printf("%s\n", mat[posf]);
    }
    fclose(file);
}
unsigned old_plater (char mat[matriculations][11]) //Da la oldest matricula
{
    int foldest=0, fpos;
    for(fpos=1;fpos<matriculations;fpos++){
            if(strcmp(&mat[foldest][7], &mat[fpos][7])>0){
                foldest=fpos;
            }
            else
            if(strcmp(&mat[foldest][7], &mat[fpos][7])==0){
                if(strncmp(&mat[foldest][2], &mat[fpos][2], 4)>0){
                    foldest=fpos;
                }
            }
        }
    return(foldest);
}
void le_cwoissant (char mat[matriculations][11]) //Imprime las matriculas
{
    int rnd, posf, posc;
    printf("Plate Generator 3000:\n");
    for(posf=0;posf<matriculations;posf++){
        printf("%s\n", mat[posf]);
    }
}
//
int main() {
    srand(time(NULL));
    char mat[matriculations][11];
    mat_gen(&mat);
    printf("Done!\n");
    printf("\n%s\n", mat[old_plater(mat)]);
    //le_cwoissant(mat);
}
