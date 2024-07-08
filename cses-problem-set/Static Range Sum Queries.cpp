#include <bits/stdc++.h>
using namespace std;

#define MAX 212345

typedef long long ll;

ll v[MAX];
ll seg[4*MAX];
int n, q; 

void read(){
	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> v[i];
}

int build(int p, int l, int r){
	if(l == r) return seg[p] = v[l];
	int m = (l + r)/2;
	return seg[p] = min(build(2*p, l, m), build(2*p + 1, m + 1, r));
}

int main(){
	read();
	build(1, 0, n-1);	
	for(int i = 0; i < n; i++)
		cout << seg[i] << ' '; 
	cout << endl;
	return 0;
}
