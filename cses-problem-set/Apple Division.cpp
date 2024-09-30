#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 20 + 10

typedef long long ll;

ll n, sum;
ll v[MAX];

void read() {
	cin >> n; 
	for(int i = 1; i <= n; i++)
		cin >> v[i];
}

ll solve(ll it, ll sum1, ll sum2) {
	if(it == (n + 1)) return abs(sum1 - sum2);
	ll opt1 = solve(it + 1, sum1 + v[it], sum2); 
	ll opt2 = solve(it + 1, sum1, sum2 + v[it]);
	return min(opt1, opt2);
}

int main() {
	fastio;
	read();	
	cout << solve(1, 0, 0) << '\n';
	return 0;
}
