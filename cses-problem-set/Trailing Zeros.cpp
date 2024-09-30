// TO-DO
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back

ll solve(ll n, ll pot5) {
	if(pot5 > n) return 0;
	return solve(n, pot5*5) + floor(n/pot5); 
}

int main() {
	fastio;
	ll n; cin >> n;
	cout << solve(n, 5) << '\n';
	return 0;
}
