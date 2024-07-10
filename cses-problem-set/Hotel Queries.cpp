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

void answer(){
	for(int i = 1; i <= m; i++){
		// para cada consulta:
		// realiza uma busca na árvore de segmentos de custo 0(logn)
		// essa busca sempre prioriza os elementos que estão nos ramos da
		// esquerda da árvore. 
		// imprima o nó.
		// após o nó ser utilizado, modifique o valor do nó utilizado para -1.
	}
}

int main(){
	read();
	build_seg(1, 0, n-1);
        answer();
	return 0;
}



