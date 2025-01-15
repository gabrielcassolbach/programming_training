#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

#define fastio ios_base::sync_with_stdio(false); cin.tie(0);  
#define pb push_back

const ll INF = 1e9 + 10; 

typedef struct {
	ll a, b, c; 
} Edge;

ll n, m; 
vector<Edge> e; 
vector<ll> dist;
vector<int> r; 

void read() {
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		ll a, b, c; cin >> a >> b >> c;
		e.pb({a, b, c});	
	}
	r.resize(n + 10); 
	dist.resize(n + 10, 0);	
}

int solve() {
	int x;
	for(int i = 1; i <= n; i++) {	
		x = -1;
		for(auto u : e) {
			if(dist[u.a] + u.c < dist[u.b]){
				dist[u.b] = (dist[u.a] + u.c);
				r[u.b] = u.a;
				x = u.b;
			} 
		} 
	}	
	return x; 
}

void ans(int node) {
	if(node == -1) {cout << "NO\n"; return;}
	cout << "YES\n";
	for(int i = 1; i <= n; i++) 
		node = r[node];
	vector<int> cycle;
	int aux = node;
	for(int v = node; ; v = r[v]) {
		cycle.pb(v);
		if(v == node and cycle.size() > 1) break;
	}
	reverse(cycle.begin(), cycle.end());
	for(auto it = cycle.begin(); it != cycle.end(); it++)
		cout << *it << " ";
	cout << '\n';
}

int main() {
	fastio; 
	read();	
	ans(solve());
	return 0; 
}	



