#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 1123
#define INF 99

typedef long long ll;

ll n; vector<ll> v; 
ll dp[MAX][MAX];

void read(){
	cin >> n; v.resize(n+10); v[0] = 0;
	for(int i = 1; i <= n; i++) cin >> v[i];
}

void init_dp(){
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n; j++)
			dp[i][j] = -1;
}

void debug() {
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= n; j++){
			cout << dp[i][j] << "   ";
		}
		cout << endl;
	}
}

ll solve(int p, int t) {
	if(p == n) return dp[p][t] = 0; // 
	if(dp[p][t] != -1) return dp[p][t];
	dp[p][t] = solve(p+1, t) + abs(v[p+1] - v[p]);
	dp[p][t] = min(dp[p][t], solve(p+1,p) + abs(v[p+1]-v[t]));
	return dp[p][t];
}

int main() { _
	read();
	init_dp();
	cout << solve(0, 0) << endl;
	//debug();
	return 0;
}
