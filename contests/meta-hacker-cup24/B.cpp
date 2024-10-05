#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define MAX 11234567

int primes[MAX];
vector<ll> v; 
ll n;

ll find(ll val, ll l, ll r) { 
	if(abs(r - l) == 1) return l;
	ll m = (l + r)/2;
	if(v[m] == val) return m;
	if(v[m] > val) return find(val, l, m);
	return find(val, m, r);
}

ll solve() {	
	ll pos = find(n, 0, v.size()-1);	
	return pos;
}

void init() {
	for(int i = 0; i < MAX; i++) primes[i] = -1;
}

void prime_numbers() {
	for(int i = 2; i < MAX; i++) {
		if(primes[i] == -1) primes[i] = 1;
		for(int j = 2*i; j < MAX; j += i) 
			primes[j] = 0;
	}
	for(int i = 2; i < MAX; i++) if(primes[i]) v.pb(i);
}

int main() {
	fastio;	
	int t; cin >> t;
	init();
	prime_numbers();
	for(int i = 1; i <= t; i++) {
		cin >> n;
		cout << "Case #" << i << ": "; 
		if(n < 5) cout << 0 << '\n';
		else cout << solve() << '\n';	
	}
	return 0;
}


