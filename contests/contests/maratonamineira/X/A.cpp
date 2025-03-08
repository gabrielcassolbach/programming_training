#include <bits/stdc++.h>
using namespace std;

#define MAX 5

int main(){ 
	int v[MAX];
	for(int i = 1; i < MAX; i++) cin >> v[i];
	if(v[2] == 1 && v[3] == 2 && v[4] == 3)
		{cout << 1 << endl; return 0;}
	if(v[1] == 1 && v[3] == 1 && v[4] == 2)
		{cout << 2 << endl; return 0;}	
	if(v[1] == 2 && v[2] == 1 && v[4] == 1)
		{cout << 3 << endl; return 0;}
	if(v[1] == 3 && v[2] == 2 && v[3] == 1)
		{cout << 4 << endl; return 0;}
	return 0;	
}

