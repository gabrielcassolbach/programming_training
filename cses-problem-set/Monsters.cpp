#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 1123
#define f first
#define s second


ll n, m; 
pair<int, int> b; 
pair<char, int> matrix[MAX][MAX];

void read() {
	cin >> n >> m; 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> matrix[i][j].f;
			if(matrix[i][j] == 'A')	
				{b.first = i; b.second = j;}
			matrix[i][j].s = -1;
		}
	}
}

bool outOfMaze(pair<int, int> pt) {
	if(

}

void solve() {
	queue<int, int> q; 
	q.push(b);
	while(!q.empty()) {
		pair<int, int> pt = q.front();
		q.pop(); 
		if(outOfMaze(pt))  

	}
}

int main() {
	fastio;
	read();	
	solve();
	return 0;
}

