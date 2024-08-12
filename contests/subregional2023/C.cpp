#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;

const ll INF = 1e9;

vector<ll> values; // os pesos dos nós; 
vector<ll> vis;
vector<vector<ll>> graph; // forma o grafo.
vector<ll> ans;
ll n;

void read(){
    cin >> n; 
    values.resize(n + 10); 
    vis.resize(n+10, 0);
    graph.resize(n + 10);
    ans.resize(n + 10);
    for(int i = 2; i <= n; i++){
        ll vertex; cin >> vertex; 
        graph[vertex].push_back(i); 
        graph[i].push_back(vertex); 
    }
    for(int i = 1; i <= n; i++) 
        {cin >> values[i];}
}

void dfs(ll node, vector<ll> & d){
    vis[node] = true;
    ll l = upper_bound(d.begin(), d.end(), values[node]) - d.begin(); // logn.
	ll ant_val = d[l]; 
    if(d[l-1] < values[node] && values[node] < d[l])
			{d[l] = values[node];}
    for (auto it = graph[node].begin(); it != graph[node].end(); it++){ 
        if(!vis[*it]){
            dfs(*it, d);
        }
    }

	ll lb = lower_bound(d.begin(), d.end(), INF) - d.begin() - 1;
    ans[node] = lb;
    d[l] = ant_val;
}

int main(){
    read();
    vector<ll> dp; dp.resize(n + 10, INF); 
    dp[0] = -INF;
    dfs(1, dp);
    for(int i = 2; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
