#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;

string ans(ll a, ll b) {
	if(a == 0 && b == 0) return "YES";
	if(a == 0 || b == 0) return "NO";
	if(min(a,b)*2 < max(a,b)) return "NO";
	return !((a+b)%3) ? "YES" : "NO";
}

int main() {
	fastio;
	int t; cin >> t;
	while(t--) {
		ll a, b; cin >> a >> b;
	    cout << ans(a, b) << '\n';         
	}
	return 0;
}
