#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0):
#define pb push_back

const ll mod = 1e9 + 7;

ll expo_two(ll n){
	if(n == 0) return 1;
	return (expo_two(n-1)*2)%mod;
}

int main() {
	ll n; cin >> n;	
	cout << expo_two(n) << '\n';
	return 0;
}


