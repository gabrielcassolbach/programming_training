#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back

vector<vector<int>> g; 
vector<int> grau_e; 
int n; 

void set_graph() {
	cin >> n;
	g.resize(n); grau_e.resize(n, 0); 
	for(int i = 0; i < n; i++) {
		int q; cin >> q;
		for(int j = 0; j < q; j++){
			int val; cin >> val;
			g[i].pb(val); 
			grau_e[val-1]++; 
		} 
	} 	
}

int find_first(int v, int size) {
	if(size == 1) return 1; 
	int next_node = -1; 
	for(auto u : g[v-1]) { 
		--grau_e[u-1]; 	 
		if(!grau_e[u-1]) next_node = u; 
	}
	if(next_node == -1) return 0;  
	return find_first(next_node, size - 1);
} 

int get_first() {
	for(int i = 0; i < n; i++){
		if(!grau_e[i]) return (i+1);
	}
	return -1; 
}

int main() {
	fastio;
	set_graph();
	int first_v = get_first();
	if(first_v == -1) {cout << 0 << '\n'; return 0;}
	int num_v = n; 
	cout << find_first(first_v, num_v) << '\n'; 	
	return 0; 
}

