#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll; 

ll n; 

ll solve() {
	ll val; ll ans = 0; 
		
	for(int i = 0; i < n; i++) {
		cin >> val; //cout << val << " ";  
		if(ans + val <= 300) ans += val; 	
	}	
	//cout << '\n';
	return ans;
}

int main() {
	fastio; 	
	do {
		cin >> n;
		if(n) 
			cout << solve() << '\n'; 
	}while(n);
	return 0; 
}
