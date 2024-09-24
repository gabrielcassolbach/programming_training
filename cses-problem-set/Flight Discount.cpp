#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pb push_back
#define in insert
#define ii pair<ll, ll>

const ll INF = 1e17 + 10;

vector<vector<ii>> graph, opp_graph;
vector<ll> path;
vector<bool> vis;
vector<ll> distances;
priority_queue<ii> q;
ll n, m;

void read() {
	cin >> n >> m;
	graph.resize(n + 10); opp_graph.resize(n + 10);
	while(m--){
		ll a, b, c; cin >> a >> b >> c;
		graph[a].pb({c, b});
		opp_graph[b].pb({c, a});
	}
}

void init() {
	vis.resize(n + 10, false);
	distances.resize(n + 10, INF);
}

void dijkstra() {
	distances[1] = 0;
	q.push({0, 1}); 
	while(!q.empty()){
	 	ii edge = q.top(); q.pop();
		ll node = edge.second; ll cost = edge.first;
		if(vis[node]) continue;
		cout << "node " << node << '\n';
		vis[node] = true; 
		for(auto u : graph[node]) {
			ll b = u.second; ll w = u.first;
			if(distances[node] + w < distances[b]) {
				distances[b] = distances[node] + w;
				q.push({-distances[b], b});
			}
		}
	}
}

void solve(ll node){
	cout << node  << '\n';
	vis[node] = true;
	if(node == 1) return ;
	ll next_node = -1; ll m_dist = INF;
	for(auto u : opp_graph[node]) {
		if((distances[u.second] < m_dist) && !vis[u.second]) {
			m_dist = distances[u.second];
			next_node = u.second;
		}		
	}
	if(next_node != -1){
		path.pb(abs(m_dist));
		return solve(next_node);
	}
	return;
}

ll answer() {
	ll ans = 0; vector<ll> choices;
	
	for(int i = 1; i < path.size(); i++) 
		choices.pb(abs(path[i] - path[i-1]));
	
	sort(choices.begin(), choices.end());
	int i;
	if(choices.size() == 0) return ans; 
	for(i = 0; i < choices.size() - 1; i++) 
		ans += choices[i];

	ans += floor(choices[i]/2);
	return ans;
}

void debug() {
	for(int i = 0; i <= distances.size(); i++) cout << distances[i] << " ";
	cout << '\n';
}


int main() {
	read(); init();
	dijkstra();
	for(int i = 1; i <= n; i++) vis[i] = false;
	path.pb(distances[n]); solve(n);
	cout << answer() << '\n';	
	//debug();
	return 0;
}







