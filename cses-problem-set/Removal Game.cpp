#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 5123

const ll inf = -1e5;

ll n; vector<ll> v;
ll dp[MAX][MAX];

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
	//cout << "a: " << a << " b: " << b << '\n';
	if(a == b) return v[a];
	if(dp[a][b] != -2) {
		//cout << dp[a][b] << " ";
		return dp[a][b];
	}

	if(b - a == 1) return choice(a, b, p);
	if(p) 
		dp[a][b] = max(solve(a+1, b, p^1)+v[a], solve(a,b-1,p^1)+v[b]);
	else
		dp[a][b] = min(solve(a+1, b,p^1), solve(a, b-1,p^1));
	return dp[a][b];
}

int main() {
	fastio; read(); memset(dp, -2, sizeof dp);
	cout << dp[1][1] << '\n';
	cout << solve(1, n, 1) << '\n';	
	return 0;
}


