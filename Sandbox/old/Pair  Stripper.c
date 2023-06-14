// Quitar los pares de un número

long strip_pairs (long n){
    long aux=0;
    for(;n;n/=10){
        if(n%2){
            aux=aux*10+n%10;
        }
    }
    for(;aux;aux/=10){
            n=n*10+aux%10;
        }
    return(n);
}

int main(){
    long n;
    printf("Introduzca unos numbers: ");
    scanf("%li", &n);
    printf("%li", strip_pairs(n));
};
