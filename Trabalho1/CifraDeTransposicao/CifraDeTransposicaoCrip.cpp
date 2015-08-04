#include <stdio.h>
#include <vector> 

using namespace std;


#define pb push_back

vector < vector <char> > M;

int main(int argc, char *argv[] ){
	int chave;
	sscanf(argv[1], "%d", &chave);
	
	char a;
	int i = 0;
	vector <char > v;
	
	while (scanf("%c", &a)!=EOF){
		v.pb(a);
		i++;
		
		if (i == chave){
			M.pb(v);
			i = 0 ;
			v.clear();
		//	printf("\n");
		}
	}
	
	bool ff = false;
	
	while (i < chave){
		ff = true; 
		v.pb('\0');
		i++;
	}
	
	if (ff) M.pb(v);
	
	for (int j =0 ; j < chave;j++){
		for (i = 0 ; i  < (int)M.size();i++){
			printf("%c", M[ i ][ j ]);
		}
	}
	
	return 0;
}
