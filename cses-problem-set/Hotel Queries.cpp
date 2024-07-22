#include <bits/stdc++.h>
using namespace std;

#define MAX 212345 

typedef long long ll;

vector<ll> h; vector<ll> g;
ll n, m;
ll seg[4*MAX]; 

void read(){
	cin >> n >> m; 
	h.resize(n + 10); g.resize(m + 10);
	for(int i = 1; i <= n; i++) cin >> h[i];
	for(int i = 1; i <= m; i++) cin >> g[i];
}

ll build_seg(ll p, ll l, ll r){
	if(l == r) return seg[p] = h[l];	
	ll m = (l+r)/2;
	return seg[p] = max(build_seg(2*p, l, m), build_seg(2*p + 1, m + 1, r));
}

ll solve(ll val, ll p, ll l, ll r) {
	if(l == r) return l;
	ll m = (l + r)/2;
	if(seg[2*p] >= val) 
		return solve(val, 2*p, l, m);
	else 
		return solve(val, 2*p + 1, m + 1, r);
}

ll update(ll index, ll x, ll p, ll l, ll r) {
	if(index < l or index > r) return seg[p];
	if(l == r) return h[l] = seg[p] = x;
	ll m = (l+r)/2;
	return seg[p] = max(update(index, x, 2*p, l, m), update(index, x, 2*p + 1, m + 1, r));
}

void queries(){
	ll ans = 0;
	for(int i = 1; i <= m; i++){
		if(g[i] > seg[1]){
			cout << 0 << " ";
		}else{			
			ans = solve(g[i], 1, 1, n);
			cout << ans << " ";
			update(ans, h[ans] - g[i], 1, 1, n);	
		}	
	}
	cout << endl;
}

int main(){
	read();	
	build_seg(1, 1, n);
	queries();	
	return 0;
}

