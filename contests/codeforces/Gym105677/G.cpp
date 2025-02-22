#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); 

int main() {
	ll r, n; cin >> r >> n;
	ll a = 0, b = r; 

	for(int i = 0; i < n; i++) {
		ll val; cin >> val; 
		a += val; b += val; 	
		a = max(0ll, min(r, a));		
		b = max(0ll, min(r, b)); 
	}	
	
	string ans = (a == b) ? to_string(a) : "uncertain";
	ans += '\n'; 

	cout << ans; 

	return 0; 
}


