#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 5123

ll n; vector<ll> v;
ll dp[MAX][MAX];

/*
4
4 5 1 3
*/ 

void read() {
	cin >> n; v.resize(n + 10);
	for(int i = 1; i <= n; i++)
		cin >> v[i];
}

ll choice(ll a, ll b, ll p) {
	if(p) return max(v[a], v[b]);
	return min(v[a], v[b]);
}

ll solve(ll a, ll b, ll p) {
	if(a == b) return v[a];
	if(dp[a][b] != -1) return dp[a][b];
	if(b - a == 1) return choice(a, b, p);
	if(p) 
		dp[a][b] = max(solve(a+1, b, p^1)+v[a], solve(a,b-1,p^1)+v[b]);
	else
		dp[a][b] = min(solve(a+1, b,p^1), solve(a, b-1,p^1));
	return dp[a][b];
}

int main() {
	fastio; read(); memset(dp, -1, sizeof dp);
	cout << solve(1, n, 1) << '\n';	
	return 0;
}


