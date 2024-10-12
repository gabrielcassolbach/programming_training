#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

// exponenciação binária.
ll power(ll a, ll b) {	
	if(b == 0) return 1;
	ll u = power(a, b/2);
	u *= u;
	return (b % 2) ? (a*u) : u;
}

ll getDigit(ll ans, ll index, ll size) {
	ll it = size - index;
	while(it--) ans /= 10;				
	return ans%10;	
}

char solve(ll n) {
	ll base = 1;		
	while(n - 9*power(10,base-1)*base > 0) {
		n -= 9*power(10, base-1)*base;
		base++;
	}

	ll ans = power(10, base-1) + (n-1)/(base);
	string s = to_string(ans);
	
	return s[(n-1)%base];	
}

int main() {
	fastio;	
	int q; cin >> q;
	while(q--) {
		ll n; cin >> n;
		cout << solve(n) << '\n';
	}
	return 0;
}


