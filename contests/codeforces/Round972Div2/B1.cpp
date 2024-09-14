#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9 + 10

typedef long long ll;

int m, q;
ll n, b1, b2, a1;

int between() {
	if(a1 < b2 && a1 > b1) 
		return 1;
	if(a1 < b1 && a1 > b2)
		return 1;
	return 0;
}

ll solve() {
	ll dist = INF;
	if(between()) {
		dist = min(dist, abs(((b1 + b2)/(ll)2) - b2));
		dist = min(dist, abs(((b1 + b2)/(ll)2) - b1));
	}else {
		ll lwe_pt = min(b1, b2);
		ll upp_pt = max(b1, b2);
		if(a1 > upp_pt)
			dist = abs(n-upp_pt);
		else
			dist = abs(lwe_pt - 1);
	}
	return dist;
}

int main() { _
	int t; cin >> t;
	while(t--) {
		cin >> n >> m >> q;
		cin >> b1 >> b2;
		cin >> a1; 		
		cout << solve() << '\n';
	}	
	return 0;
}



