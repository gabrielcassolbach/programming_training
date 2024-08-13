#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;

int main() { _
	ll pref[2] = {1, 0};
	ll n; cin >> n;
	ll mask = 0; ll ans = 0; ll cont = 0;
	while(n--) {
		ll val; cin >> val;
		cont += val; 
		mask = (cont % 2 != 0); 		
		pref[mask]++;
		ans += pref[!mask];		
	}
	cout << ans << endl;
	return 0;
}
	
