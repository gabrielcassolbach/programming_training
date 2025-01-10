#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); 

typedef long long ll; 
ll x, y; 

ll ans() {
	cin >> x >> y;
	if((x < 0 && y < 0) || (x > 0 && y > 0))
		return abs(x) + abs(y); 
	return max(abs(x), abs(y)); 
}

int main() {
	fastio; 
	ll n; cin >> n; 
	while(n--){
		cout << ans() << '\n'; 
	}
	return 0; 
}
