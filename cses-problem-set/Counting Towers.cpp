#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
#define MAX 1000010

const ll mod = 1e9 + 7;

ll f[MAX], s[MAX];
ll n; 

ll splitTop(ll n); 
ll flatTop(ll n);

ll splitTop(ll n) {
	if(n == 1) return 1;
	if(s[n] != -1) return s[n];
	s[n] = (flatTop(n-1) + 4*splitTop(n-1)) % mod;
	return s[n];
}

ll flatTop(ll n) {
	if(n == 1) return 1;
	if(f[n] != -1) return f[n];
	f[n] = (2*flatTop(n-1) + splitTop(n-1)) % mod;
	return f[n];
}

int main() {
	fastio; int t; cin >> t;
	memset(f, -1, sizeof f); memset(s, -1, sizeof s); 
	while(t--){
		cin >> n;
		cout << (flatTop(n) + splitTop(n)) % mod << '\n';
	}
	return 0;
}
