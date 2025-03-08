#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const ll INF = 1e9;
ll n;

double solve(){
	cin >> n; ll min_fin = INF; ll pos = -1;
	ll prev_a, prev_b; prev_a = prev_b = -INF;
	for(int i = 1; i <= n; i++) {
		ll a, b; cin >> a >> b;
		if(b <= prev_a) return -1;
		min_fin = min(min_fin, b); 
		if(min_fin == b) pos = i;
		prev_a = a; prev_b = b;
	}
	return double(pos/(double)min_fin);
}

int main(){
	fastio;
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": "; 
		cout << solve() << '\n';
	}
	return 0;
}
