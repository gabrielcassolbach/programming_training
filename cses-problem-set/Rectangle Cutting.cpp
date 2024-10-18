#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 512

const ll INF = 1e9 + 10;

ll dp[MAX][MAX];

void init() {
	for(int i = 0; i < MAX; i++)
		for(int j = 0; j < MAX; j++)
			dp[i][j] = INF;
}

ll solve(int a, int b) {
	if(a == b) return 1;
	if(dp[a][b] != INF) return dp[a][b];	
	
	for(int i = 1; i <= b-1; i++) 
		dp[a][b] = min(dp[a][b], solve(a, i) + solve(a, b-i));
	 
	for(int i = 1; i <= a-1; i++)
		dp[a][b] = min(dp[a][b], solve(i, b) + solve(a-i, b));

	return dp[a][b];
}

int main() {
	fastio;
	int a, b; cin >> a >> b;
	init();
	cout << solve(a, b) - 1<< '\n';
	return 0;
}


