#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ii pair<ll, ll>
#define MAX 64321
#define MAX2 512

const ll mod = 1e9 + 7;
ll dp[MAX][MAX2];

/*
62625 = 6.10⁴*5.10² = 3*107

*/

ll solve(ll n, ll sum, ll setsum, ll it){
	if(it == n + 1 || sum > setsum) return 0;
	if(sum == setsum) {return 1;}
	if(dp[sum][it] != -1) return dp[sum][it];
	dp[sum][it] = solve(n, sum + it, setsum, it + 1) + solve(n, sum, setsum, it + 1);
	return dp[sum][it] % mod;
}

ll soma(ll n){
	ll sum = 0; n++;
	while(n--) sum += n;
	return sum;
}

void init() {
	for(int i = 0; i < MAX; i++)
		for(int j = 0; j < MAX2; j++)
			dp[i][j] = -1;
}

ll hasSol(ll n) {
	ll sum = soma(n);
	if(sum % 2) return 0; 
	return (sum/2);
}

int main() {
	fastio;
	init();
	ll n; cin >> n;
	ll sol = hasSol(n);
	if(!sol)
		cout << 0 << '\n';
	else
		cout << solve(n, 0, sol, 1) << '\n';	
	return 0;
}


