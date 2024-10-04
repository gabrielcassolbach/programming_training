#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back

typedef long long ll;

vector<string> ans;

void duplicate() {
	for(int j = ans.size()-1; j >= 0; j--) 
		ans.pb(ans[j]);
}

void append_zeros() {
	for(int j = 0; j < ans.size()/2; j++)
		ans[j] = "0" + ans[j];
}

void append_ones(){
	for(int j = ans.size()/2; j < ans.size(); j++)
		ans[j] = "1" + ans[j];
}

void solve(ll n) {
	for(int i = 2; i <= n; i++){
		duplicate();
		append_zeros();
		append_ones();
	}
}

int main() {
	fastio;
	ll n; cin >> n;
	ans.pb("0"); ans.pb("1"); solve(n);
	for(int i = 0; i < ans.size(); i++) 
		cout << ans[i] << "\n";
	return 0;
}




