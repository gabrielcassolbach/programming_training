#include <bits/stdc++.h>
using namespace std;

#define MAX 212345

typedef long long ll;

ll v[MAX], p[MAX];
int n, q; 

void read(){
	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> v[i];
}

void setp(){
	p[0] = v[0];
	for(int i = 1; i < n; i++) 
		p[i] = p[i-1] + v[i];
}

int main(){
	read();
	setp();
	while(q--){
		int l, r; cin >> l >> r;
		l--; r--; 
		ll ans = p[r];
		if(l > 0) ans -= p[l-1];
		cout << ans << endl;
	}
	return 0;
}
