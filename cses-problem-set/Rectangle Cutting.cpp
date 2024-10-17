#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 512

ll dp[MAX][MAX];

void init() {
	for(int i = 0; i < MAX; i++)
		for(int j = 0; j < MAX; j++)
			dp[i][j] = 0;
}

ll solve(int a, int b) {
	//cout << a << " " << b << '\n';
	if(dp[a][b]) return dp[a][b];	
	if(a == b) return 1; 
	if(a > b)        //         (3, 5)         (5, 5)
		return dp[a][b] = solve(a-b, b) + 1;
	else             //        (3, 5)           3  3  
		return dp[a][b] = solve(a, b-a) + 1;
}

int main() {
	int a, b; cin >> a >> b;
	init();
	cout << solve(a, b) - 1 << '\n';
	return 0;
}
