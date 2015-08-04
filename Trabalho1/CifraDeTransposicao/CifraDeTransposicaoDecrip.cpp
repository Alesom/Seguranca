#include <stdio.h>
#include <vector> 

#define pq push_back

vector < vector <char> > M;

int main(int argc, char *argv[] ){
	int chave;
	sscanf(argv[1], "%d", &chave);
	char a;
	int i = 0;
	vector <char > v;
	
	
	while (scanf("%c", &a)!=EOF){
		v.pb(a);
		if (i==chave){
			M.pb(v);
			i =0 ;
		}
		i++;
	}
	
	while (i < chave) v.pb('\0');
	
	for (i = 0 ; i  < M.size();i++){
		for (int j =0 ; j < M[i].size();j++){
			printf("%c",  M[j][i] );
		}
	}
	
	return 0;
}
