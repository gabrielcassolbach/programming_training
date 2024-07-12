#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAX 212345

ll n, m;
vector<ll> h, g; 
ll seg[4*MAX];

void read(){
	cin >> n >> m;
	h.resize(n + 3); g.resize(m + 3); 
	for(int i = 1; i <= n; i++) cin >> h[i]; 
	for(int i = 1; i <= m; i++) cin >> g[i];
}

ll build_seg(int p, int l, int r){
	if(l == r) return seg[p] = h[l];
	int m = (l+r)/2;
	return seg[p] = max(build_seg(2*p, l, m), build_seg(2*p + 1, m+1, r));
}

ll query(ll a, ll b, ll p, ll l, ll r) {

}

void update_seg(){
	
}

void answer(){
	for(int i = 1; i <= m; i++){
		cout << hotel(1, g[i]) << endl;
		update_seg();
	}
}

int main(){
	read();
	build_seg(1, 0, n-1);
        answer();
	return 0;
}

