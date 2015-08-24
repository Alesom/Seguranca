#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <stdlib.h>

#define pb push_back

using namespace std;


bool Cesar (FILE *n, FILE *o, int &key){
	vector <char> vn;
	vector <char> vo;
	char a;
	
	fseek(n, 0, SEEK_SET);
	while (!feof( n )){
		fread(&a, sizeof(char), 1, n);
		vn.pb(a);
	}
	
	fseek(o, 0, SEEK_SET);
	while (!feof( o )){
		fread(&a, sizeof(char), 1, o);
		vo.pb(a);
	}
	
	int auxkey;
	
	for (unsigned i = 0 ; i < vo.size();i++){
		if (i==0) auxkey = abs (vn[i] - vo[i]);
		else 
			if (auxkey != abs(vn[i] - vo[i])) return false;
		
	}
	
	key = auxkey;
	
	return true;
}


bool Transposicao (FILE *n, FILE *o, int &key){
	return false;
}

bool Substituicao (FILE *n, FILE *o, map < char, char > & m){
	vector <char> vn;
	vector <char> vo;
	char a;
	map < char, char> mp;
	
	fseek(n, 0, SEEK_SET);
	while (!feof( n )){
		fread(&a, sizeof(char), 1, n);
		vn.pb(a);
	}
	
	fseek(o, 0, SEEK_SET);
	while (!feof( o )){
		fread(&a, sizeof(char), 1, o);
		vo.pb(a);
	}
	
	for (int i = 0 ; i < (int)vo.size();i++){
		if (mp.find(vn[i])==mp.end()){
			mp[vn[i]] = vo[i];
		}else{
			if (mp[vn[i]] != vo[i]) return false;
		}
	}
	
	for (map <char, char> :: iterator i = mp.begin(); i != mp.end();i++){
		m[ (*i).first ] = (*i).second;
	}
	return true;
}

bool Vigenere (FILE *n, FILE *o, vector < char > & s){
	vector <char> vn;
	vector <char> vo;
	vector < char> resp;
	
	char a;
	
	fseek(n, 0, SEEK_SET);
	while (!feof( n )){
		fread(&a, sizeof(char), 1, n);
		vn.pb(a);
	}
	
	fseek(o, 0, SEEK_SET);
	while (!feof( o )){
		fread(&a, sizeof(char), 1, o);
		vo.pb(a);
	}
	
	map < char, int > mp;
	int intervalo;
	int i;
	int j;
	
	for (i = 1 ; i < (int)vo.size();i++){
		
		for (j = 0; j < (int ) vo.size();j += i){
			if (j==0) intervalo = abs(vn[i] - vo[i]);
			else{
				if (intervalo != abs(vn[i] - vo[i]) ) break;
			}
		}
		
		if (j >= (int)vo.size()){
			break;
		}
	}
	
	
	if (i==(int)vo.size()) return false;
	
	for (j = 0 ; j  < intervalo; j++){
		resp.pb(vn[i] - vo[i]);
	}
	
	
	for (i = 0 ; i < (int)vo.size();i++){
		if ( resp[i % resp.size()] != abs(vn[i] - vo[i])) return false;
	}
	
	
	for (i = 0; i < (int)resp.size();i++){
		s.pb(resp[i]);
	}
	
	return true;
}


int main(int argc, char *argv[]){
	FILE *normal;
	FILE *oculto;
	
	if ( (normal = fopen(argv[1], "r")) == NULL) { printf("ERROR\n"); return 0;}
	if ( (oculto= fopen(argv[2], "r")) == NULL) { printf("ERROR\n"); return 0;}
	
	int resp;
	map < char, char> respSub;
	vector <char> respVig;
	
	
	if (Cesar( normal, oculto, resp)){
		printf("Cifra de Cesar! Chave: %d\n", resp);
	}else if (Transposicao( normal, oculto, resp)){
		
		printf("Cifra de Transposicao! Chave: %d\n", resp);
	}else if (Substituicao( normal, oculto, respSub)){
		
		printf("Cifra de Substituicao! Chave:\n");
		for (map <char,char> :: iterator i = respSub.begin(); i != respSub.end();i++) 
			printf("%d %d\n", (*i).first, (*i).second);
		
	}else if (Vigenere( normal, oculto, respVig)){
		printf("Cifra de Vigenere! Chave: ");
		for (unsigned i =0 ; i < respVig.size();i++) 
			printf("%c", respVig[i]);
	}
	
	
	fclose(normal);
	fclose(oculto);
	
	return 0;
}
