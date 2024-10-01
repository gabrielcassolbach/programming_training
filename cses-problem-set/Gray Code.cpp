#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back

typedef long long ll;

vector<string> _a, _b;

void solve (int n, string a, string b) {
	if(n == 1) {_a.pb(a); _b.pb(b); return;}	
	solve(n-1, a+"0", b+"1");
	solve(n-1, a+"1", b+"0");
}

int main() {
	fastio;
	ll n; cin >> n; 
	solve(n, "0", "1");
	for(int i = 0; i < _a.size(); i += 2) {
				

	
		cout << _a[i] << '\n';
	}

	for(auto i = _b.begin(); i != _b.end(); i++) cout << (*i) << '\n';
	return 0;
}
