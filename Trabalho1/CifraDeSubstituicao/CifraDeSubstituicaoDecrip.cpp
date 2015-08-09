#include <stdio.h>
#include <stdlib.h>

#include <map>

using namespace std;

map < int, char> Ci;

int main(int argc, char *argv[]){
	char aux;
	
	FILE *chave = fopen(argv[1], "r");
	FILE *texto = fopen(argv[2], "r");
	
	fseek(chave, 0, SEEK_SET);
	int i=0;
	
	while (!feof( chave ) && i < 256){
		fread(&aux, sizeof(char), 1, chave);
		Ci[ i ] = aux;
		i++;
	}
	
	fseek(texto, 0, SEEK_SET);
		
	while (!feof( texto )){
		fread(&aux, sizeof(char), 1, texto);
		printf("%c",  Ci[ aux ] );
	}
	
	fclose(chave);
	fclose(texto);
	
	return 0;
}
