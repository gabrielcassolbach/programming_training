#include <bits/stdc++.h>
using namespace std;

#define MAX 212345

char v[MAX];
int freq[MAX];
int tam = 0;

void init() {
	for(int i = 0; i < MAX; i++) freq[i] = 0;
}

void read(){
	char c;
	while(scanf("%c", &c) != EOF){
		v[tam++] = c;
	}
	tam--;
}

void print_ans(){
	for(int i = 1; i < MAX; i++){
		if(!freq[i]) {cout << i << endl; return;}
	}	
}

void solve(){
	// passar pelo vetor e buscar todos os dígitos de tam: {1, 2, 3, 4, 5, 6}	
	for(int i = 1; i <= 6; i++) { 
		for(int j = 0; j < (tam-i+1); j++) {
			//cout << "val: " << i << "j: " << j << endl;
			string sr = "";
			for(int k = j; k < j + i; k++) {
				char dig = v[k];
				sr.push_back(dig);
			}
			//cout << "debug: " << sr << endl;
			if(stoi(sr) < MAX)
				freq[stoi(sr)]++;
		}
	}
	print_ans();
}

int main(){
	init();
	read();
	solve();
	return 0;
}
