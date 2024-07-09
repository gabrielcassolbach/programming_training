#include <bits/stdc++.h>
using namespace std;

#define MAX 212345
#define INF INT_MAX

typedef long long ll;

int n, q;
ll v[MAX];
ll seg[MAX];

void read(){
	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> v[i];
}

ll build(int p, int l, int r){
	if(l == r) return seg[p] = v[l];
	int m = (l + r)/2;
	return seg[p] = min(build(2*p, l, m), build(2*p + 1, m + 1, r));
}

ll query(int a, int b, int p, int l, int r){
	if(b < l or r < a) return INF;
	if(a <= l and r <= b) return seg[p];
	int m = (l+r)/2;
	return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
}

int main(){
	read();
	build(1, 0, n-1);
	while(q--){
		int a, b; cin >> a >> b;
		a--; b--; 
		cout << query(a, b, 1, 0, n-1) << endl;
	}
	return 0;
}
