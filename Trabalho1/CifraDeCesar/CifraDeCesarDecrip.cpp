#include <stdio.h>

int main( int argc, char *argv[] ){
	char a;
	int chave;
	
	sscanf(argv[1], "%d", &chave);
	
	while (scanf("%c", &a) != EOF){
		printf("%c", (a  + 256 - chave) % 256);  
	}
	
	
	
	
	return 0;
}
