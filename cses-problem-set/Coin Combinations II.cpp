// https://usaco.guide/problems/cses-1636-coin-combinations-ii-ordered/solution
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 1123456

typedef long long ll;

const int mod = (int)1e9 + 7;
ll n, x; 
ll dp[MAX];

int main() { _
	cin >> n >> x; vector<ll> coins(n + 10);
	for(int i = 0; i < n; i++) cin >> coins[i];
	dp[0] = 1;
	for(int i = 0; i < n; i++){
		for(int weight = 0; weight <= x; weight++){
			if(weight - coins[i] >= 0){
				dp[weight] += dp[weight - coins[i]];
				dp[weight] %= mod;
			}
		}
	}
	cout << dp[x] << '\n';
	return 0;
}