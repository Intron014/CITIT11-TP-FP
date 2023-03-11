/*encriptar ASCII 1->63*/

int main (int argc, char *argv[]){
	FILE *f_in, *f_out;
	int i;
	char masc, c,nomfich[50];
	if(arg<2)
		return(1);
	if(!(f_in=fopen(argv[1],"rb")))
		return(2);
	for(i=0;nomfich[i]=argv[1][i]!='.';i++);
	nomfich[i]='a';
	for(;nomfich[i+1]=argv[1][i];i++);
	if(!(f_out=fopen(nomfich,"wb")))
		return(3);
	/**/
	prinf("Mascara");
	do{
		masc=getchar();
	}while(masc<1||masc>63);
	/**/
	fwrite(&masc,1,1,f_out);
	while(fread(&c,1,1,f_in)){
		c&=~masc;
		fwrite(&c,1,1,f_out):
	}
	fclose(f_in);
	fclose(f_out);
	return(0);
}