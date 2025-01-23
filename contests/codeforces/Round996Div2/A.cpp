#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); 

typedef long long ll; 

int main() {
	fastio; 
	int t; cin >> t; 
	while(t--) {
		int n, a, b; cin >> n >> a >> b;  
		if(abs(a-b)%2 == 0) cout << "YES\n"; 
	 	else cout << "NO\n"; 	
	}	
	return 0; 
}
