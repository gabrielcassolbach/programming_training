/*--- Bellman-Ford ---*/
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define ii pair<ll, ll>
#define vi vector<ii>
#define graph vector<vi>

typedef long long ll;

const ll INF = 1e13 + 10;

graph g;
vector<ll> dist; 
vector<ll> nodes;
vector<ll> vis;
ll n, m; 

void setGraph() {
	cin >> n >> m; 
	g.resize(n + 10); vis.resize(n + 10);
	for(int i = 1; i <= m; i++){
		ll a, b, c; cin >> a >> b >> c;
		g[a].pb({-c, b});
	}
}

void bellmannFord() {
	dist.resize(n + 10);
	for(int i = 1; i <= n; i++) 
		dist[i] = INF;
	dist[1] = 0;
	
	for(int i = 1; i <= n-1; i++) {
		for(int j = 1; j <= n; j++) {
			for(auto u : g[j]) {
				ll d = u.first; ll node = u.second;
				dist[node] = min(dist[node], dist[j] + d);
			}
		}		
	}
}

bool hasNegativeCycle() {
	bool decision = false;
	for(int j = 1; j <= n; j++) {
		for(auto u : g[j]) {
			ll d = u.first; ll node = u.second;
			ll previous = dist[node];
			dist[node] = min(dist[node], dist[j] + d);
			if(previous > dist[node]) {
				decision = true;
				nodes.pb(node);
			}
		}
	}
	return decision;
}

void setVis() {
	for(int i = 0; i < n; i++)
		vis[i] = 0;
}

int dfs(int node, int stop){
	if(node == stop) return 1;
	int ans = 0;	
	vis[node] = 1;
	for(auto edge : g[node]) {
		if(!vis[edge.second]) 
			ans = dfs(edge.second, stop);
		if(ans) return ans;
	}	

	return ans;
} 

int cycleReachable() {
	int isReachable = 0; int rCycle = 0;
	int testNode = 0;
	for(int i = 0; i < nodes.size() && !isReachable; i++) {
		setVis();
		isReachable = dfs(nodes[i], n);
		if(isReachable) testNode = nodes[i];
	}
 
	setVis();
	rCycle = dfs(1, testNode);
	return rCycle & isReachable;
}


void solve() {
	bellmannFord();
	if (hasNegativeCycle() && cycleReachable()) {cout << -1 << '\n'; return;}
	if(dist[n] < 0) 
		cout << abs(dist[n]) << '\n';
	else
		cout << -dist[n] << '\n';
}

int main() { 
	fastio;
	setGraph();
	solve();
	return 0;
}




