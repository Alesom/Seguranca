#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>

#define pb push_back

using namespace std;

vector<char> v;

int main(int argc, char *argv[]){
	char aux;
	
	FILE *chave = fopen(argv[1], "r");
	FILE *texto = fopen(argv[2], "r");
	
	fseek(chave, 0, SEEK_SET);
	//int i=0;
	
	while (!feof( chave )){
		fread(&aux, sizeof(char), 1, chave);
		v.pb(aux);
	}
	
	fseek(texto, 0, SEEK_SET);
	int i=0;
	while (!feof( texto )){
		fread(&aux, sizeof(char), 1, texto);
		printf("%c",  (aux +256 - v[ i % v.size() ] ) % 256  );
		i++;
	}
	
	fclose(chave);
	fclose(texto);
	
	return 0;
}

