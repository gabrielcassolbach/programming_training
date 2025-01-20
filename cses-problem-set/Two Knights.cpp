#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long ll;

ll pot(int val, int rep){
	if(rep == 0) return 1; 
	return val*pot(val, rep-1);
}

void solve(ll n) {
	if(n == 0) return ;
	solve(n-1); 
	cout << (pot(n, 4) - pot(n, 2))/2 - (4*(n-2)*(n-1)) << '\n';
}


int main(){
   	fastio;
	ll n; cin >> n;
	solve(n);
    return 0;
}
