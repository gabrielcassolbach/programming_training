#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

int v[MAX];
int seg[4*MAX];

int build(int p, int l, int r){
	cout << "p: " << p << "l: " << l << "r: " << r << endl;
	if(l == r) return seg[p] = v[l];
	int m = (l+r)/2;
	return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
}

int main(){
	int n; cin >> n;
	for(int i = 0; i < n; i++) cin >> v[i];
	build(1, 0, n-1);
	for(int i = 0; i < n; i++)
		cout << seg[i] << ' ';
	cout << endl;
	return 0;
}
