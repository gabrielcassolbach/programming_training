// Código feito por Bruno Monteiro.
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;
int v[MAX];
pair<int, int>  seg[4*MAX]; // {min, freqmin}

pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
	if(a.first < b.first) return a;
	if(b.first < a.first) return b;
	return {a.first, a.second + b.second};
}

pair<int, int> build(int p, int l, int r) {
	if(l == r) return seg[p] = {v[l], 1};
	int m = (l+r)/2;
	return seg[p] = combine(build(2*p, l, m), build(2*p + 1, m + 1, r))
}

pair<int, int> query(int a, int b, int p, int l, int r) {
	if(b < l or r < a) return {INT_MAX, -1};
	if(a <= l and r <= b) return seg[p];
	int m = (l + r) / 2;
	return combine(query(a, b, 2*p, l, m), query(a, b, 2*p + 1, m + 1, r));
}

pair<int, int> update(int i, int x, int p, int l, int r){
	if(
}

int main(){
	int n, q; cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> b[i];
	build(1, 0, n-1); // construção da seg-tree.
	while(q--) {
		int t; cin >> t;
		if(t == 1){ // update.
			int i, int x; cin >> i >> x;
			update(i, x, 1, 0, n-1);
		}else{ // query
			int l, r; cin >> l >> r; 
			r--;
			auto [x, y] = query(l, r, 1, 0, n-1);
			cout << x << " " << y << endl;			
		}
	}
	return 0;
}
