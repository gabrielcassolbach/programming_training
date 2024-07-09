#include <bits/stdc++.h>
using namespace std;

#define MAX 212345
#define INF INT_MAX

typedef long long ll;

ll n, q;
ll v[MAX];
ll seg[4*MAX];

void read(){
	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> v[i];
}

ll build(ll p, ll l, ll r){
	if(l == r) return seg[p] = v[l];
	ll m = (l + r)/2;
	return seg[p] = min(build(2*p, l, m), build(2*p + 1, m + 1, r));
}

ll query(ll a, ll b, ll p, ll l, ll r){
	if(b < l or r < a) return INF;
	if(a <= l and r <= b) return seg[p];
	ll m = (l+r)/2;
	return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
}

int main(){
	read();
	build(1, 0, n-1);
	while(q--){
		ll a, b; cin >> a >> b;
		a--; b--; 
		cout << query(a, b, 1, 0, n-1) << endl;
	}
	return 0;
}
