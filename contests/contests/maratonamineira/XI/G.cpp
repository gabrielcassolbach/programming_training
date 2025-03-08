#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

// partida / destino / custo.
ll n, m, k; 
vector<vector<pair<ll, ll>>> graph;
vector<ll> visited;
// no / custo / dist
queue<pair<ll, pair<ll, ll>>> q; 

void read(){
    cin >> n >> m >> k;
    graph.resize(n + 10);
    for(int i = 1; i <= m; i++){
        ll a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    visited.resize(n + 10);
    for (ll i = 1; i <= n; i++)
        visited[i] = -1;    
}

ll solve() {
    q.push({1, {0, 0}}); 
    while(!q.empty()) {
        pair<ll, pair<ll, ll>> p = q.front();
        q.pop();
        ll node = p.first; ll custo = p.second.first; ll dist = p.second.second;
        visited[node] = custo;
        //cout << "node: " << node << ", custo: " << custo << ", dist: " << dist << endl;
        if (node == n) return dist;
        for (ll i = 0; i < graph[node].size(); i++){
            ll new_node = graph[node][i].first;
            ll new_custo = graph[node][i].second + custo;
            //cout << "\tnew_node: " << new_node << ", new_custo: " << new_custo << endl;
            if(((visited[new_node] == -1) || (new_custo < visited[new_node])) && new_custo <= k){
                q.push({new_node, {new_custo, dist+1}});
            }
        }        
    }
    return -1;
}

int main(){
    read();
    cout << solve() << endl;
    return 0;
}

