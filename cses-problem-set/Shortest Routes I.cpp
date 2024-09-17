#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;
const ll INF = 1e15 + 10;

ll n, m;
vector<vector<pair<ll, ll>>> graph; 
vector<ll> distances; vector<bool> visited;

void read() {
	cin >> n >> m; 
	graph.resize(n + 10);
	while(m--) {
		ll city1, city2, dist;
		cin >> city1 >> city2 >> dist;
		graph[city1].push_back({dist, city2});
	}
}

void init() {
	distances.resize(n + 10);
	visited.resize(n + 10);
	for(int i = 1; i <= n; i++) {
		distances[i] = INF;
		visited[i] = false;
	}
}

void dijkstra() {
	priority_queue<pair<ll, ll>> q;

	distances[1] = 0; q.push({0, 1});
	while(!q.empty()) {
		ll node = q.top().second; q.pop();
		if(visited[node]) continue;
		visited[node] = true;
		for (auto u : graph[node]) {
			ll node2 = u.second; ll w = u.first;
			if(distances[node] + w < distances[node2]) {
				distances[node2] = distances[node] + w;
				q.push({-distances[node2], node2});
			}
		}	
	}

}

int main() { _
	read();	
	init();
	dijkstra();
	for(int i = 1; i <= n; i++) cout << distances[i] << " ";
	cout << '\n';
	return 0;
}

