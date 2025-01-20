#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define MAX 10

int p[] = {0, 1, 2, 3, 4, 5, 6, 7}; // this isn't a solution
int m[MAX][MAX];

void read() {
	char c; 
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++) {
			cin >> c;
			m[i][j] = (c == '.') ? 0 : 1; 	
		}
	}
}

int valid() {
	for(int i = 0; i < 8; i++) {
		if(m[i][p[i]]) return 0; 
		for(int j = i + 1; j < 8; j++) {
			if(j + p[j] == i + p[i]) return 0;
			if(p[j] - j == p[i] - i) return 0;	
		}	
	}	
	return 1; 
}

int main() {
	fastio;
	read();
	int ans = 0; 
	while(next_permutation(p, p + 8))
		ans += valid(); 
	cout << ans << '\n';	
	return 0; 
}





