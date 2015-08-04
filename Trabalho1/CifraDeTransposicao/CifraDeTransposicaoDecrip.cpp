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
	}
	
	int chavInv = v.size() / chave;
	
	vector <char> v1;
	
	for (i =0 ; i < (int)v.size();i++){
		if ((i%chavInv) == 0 && i){
			M.pb(v1);
			v1.clear();
		}
		v1.pb(v[i]);
	}
	
	M.pb(v1);
	for (int j =0 ; j < chavInv;j++){
		for (i = 0 ; i  < (int)M.size();i++){
			printf("%c", M[ i ][ j ]);
		}
	}
	
	return 0;
}
