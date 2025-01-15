#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define f first
#define s second

typedef long long ll; 

const ll INF = 1e9 + 10; 

ll n, m, k;
vector<vector<pair<int, ll>>> g;
priority_queue<pair<ll, int>> q;
vector<ll> dist;
vector<bool> vis; 
multiset<ll> ans; 

void read() {
	cin >> n >> m >> k;
	g.resize(n + 10);
	for(int i = 0; i < m; i++){
		ll a, b, c; cin >> a >> b >> c;  
		g[a].pb({b, c});
	}
	dist.resize(n + 10, INF); 
	vis.resize(n + 10, false); 
}

void dijkstra() {
	dist[1] = 0;
	q.push({0, 1});
	while(!q.empty()) {
		int a = q.top().s; q.pop();
		if(vis[a]) continue; vis[a] = true;
		for(auto u : g[a]){
			if(u.f == n && dist[a] + u.s != INF) ans.insert(dist[a] + u.s);
			if(dist[a] + u.s < dist[u.f]){
				dist[u.f] = dist[a] + u.s;
				q.push({-dist[u.f], u.f});
			}	
		}
	}

}

int main() {
	fastio;
	read();
	dijkstra();
	for(auto it = ans.begin(); it != ans.end(); it++) cout << *it << '\n';
	return 0;
}

