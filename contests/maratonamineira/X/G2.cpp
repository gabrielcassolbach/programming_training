#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, a, b, aux; 
	int v[4];
	v[1] = v[3] = 0; v[2] = 1;
	cin >> n;
	while(n--){
		cin >> a >> b;
		aux = v[b];
		v[b] = v[a];
		v[a] = aux;
	}
	for(int i = 1; i <= 3; i++)
		if(v[i]) cout << i << endl;
	return 0;
}
