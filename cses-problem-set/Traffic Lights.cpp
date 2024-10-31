#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define in insert 

ll n, x, a, b; 
vector<ll> v;
set<ll> v; 

bool interval(ll b, ll xi) {
		

}

ll solve(ll xi) {
	


}
 
void read() {
	cin >> x >> n; v.resize(n + 10);
	for(int i = 1; i <= n; i++) cin >> v[i];
}
 
void answer() {
	a = 0; b = x;
	for(int i = 1; i <= n; i++)
		cout << solve(v[i], a, b) << "\n";
	cout << '\n'; 
}
 
int main() {
	fastio;
	read();
	answer();
	return 0;
}
 
