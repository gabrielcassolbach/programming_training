#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pb push_back
#define in insert
#define ii pair<ll, ll>

const ll INF = 1e17 + 10;

vector<vector<ii>> graph;
vector<ll> path;
vector<bool> vis;
vector<ll> disc, full;
ll nbour;
ll n, m;

void read() {
	cin >> n >> m;
	graph.resize(n + 10); 
	while(m--){
		ll a, b, c; cin >> a >> b >> c;
		graph[a].pb({c, b});
		if(b == n) nbour = a;
	}
}

void init() {
	vis.resize(n + 10, false);
	disc.resize(n + 10, INF);
	full.resize(n + 10, INF);
}

int inNbors(ll value) {
	if(value == nbour) {nbour = -1; return 1; }
	return 0;
}

ll dijkstra() {
	priority_queue<ii> q;
	disc[1] = full[1] = 0;
	q.push({0, 1});
	while(!q.empty()) {
		ll pt = q.top().second; q.pop();
		if(vis[pt] && !inNbors(pt)) continue;
		vis[pt] = true;
		for (auto u : graph[pt]) {
			ll v = u.second; ll w = u.first;
			disc[v] = min(disc[v], min(disc[pt] + w, full[pt] + w/2));
			full[v] = min(full[v], full[pt] + w);
			q.push({-min(disc[v], full[v]), v});
		}	
	}

	return disc[n];
}
	
int main() {
	read(); init();
	cout << dijkstra() << '\n';
	return 0;
}


