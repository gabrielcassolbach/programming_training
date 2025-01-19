#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define f first
#define s second

typedef long long ll; 

const ll INF = 1e14 + 10; 

ll n, m, k;
vector<vector<pair<ll, ll>>> g;

priority_queue < 
	pair<ll, ll>,
	vector<pair<ll, ll>>,
	greater<pair<ll, ll>> 
> pq;

vector<vector<ll>> dist; 

void read() {
	cin >> n >> m >> k;
	g.resize(n + 10);
	for(int i = 0; i < m; i++){
		ll a, b, c; cin >> a >> b >> c;  
		g[a].pb({b, c});
	}
	dist.resize(n + 10);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < k; j++)
			dist[i].pb(INF);
	}
}

void dijkstra() {
	pq.push({0, 1});

	while(!pq.empty()) {
		ll u = pq.top().s; 
		ll d = pq.top().f;
		
		pq.pop();
		if(dist[u][k-1] < d) continue; 
	
		for(auto e: g[u]) {
			if(dist[e.f][k-1] > e.s+d){
				dist[e.f][k-1] = e.s+d;
				pq.push({dist[e.f][k-1], e.f}); 	
				sort(dist[e.f].begin(), dist[e.f].end());		
			}							
		}
	}
}

int main() {
	fastio;
	read();
	dijkstra();
	for(auto ans : dist[n]) cout << ans << ' ';
	cout << '\n';
	return 0;
}



