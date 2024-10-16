#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define in insert
#define MAX 1123
#define DPX 112345
#define DPY 112

int n; vector<int> v; set<int> a;
int dp[DPX][DPY];

ll solve(ll sum, ll it) {
	if(dp[sum][it]) return sum;
	if(sum) a.in(sum);
	if(it == n+1) return sum;
	dp[sum][it] = 1;
	solve(sum + v[it], it + 1); 
	solve(sum, it + 1);	
	return sum;
}

void read() {
	cin >> n; v.resize(n + 10); v[0] = 0;
	for(int i = 1; i <= n; i++) cin >> v[i];
}

void answer() {
	cout << a.size() << '\n';
	for(auto it = a.begin(); it != a.end(); it++) cout << (*it) << " ";
	cout << '\n';
}

void init() {
	for(int i = 0; i < DPX; i++)
		for(int j = 0; j < DPY; j++)
			dp[i][j] = 0;
}

int main() {
	fastio;
	read(); 
	init();
	solve(0, 1);
	answer();
	return 0;
}




