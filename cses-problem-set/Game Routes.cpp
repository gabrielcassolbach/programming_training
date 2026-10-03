#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); 

const int mod = 1e9 + 7;

int n, m;
vector<vector<int>> adj; 
vector<int> color, ans, ways;

void set_graph(){
    adj.resize(n);
    color.assign(n, 0); 
    ways.assign(n, 0); 
 
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; 
        a--; b--;
        adj[a].push_back(b);
    }
}

void dfs(int v){
    color[v] = 1;

    for(int u : adj[v])
        if(!color[u])
            dfs(u);

    ans.push_back(v);
}

int main(){
    fastio; cin >> n >> m; set_graph();
    
    dfs(0);
    reverse(ans.begin(), ans.end());    
    ll result = 1;

    ways[0] = 1;
    for(int i = 0; i < (int) ans.size(); i++){
        
        for(int u : adj[ans[i]]){
            ways[u] += ways[ans[i]];
            ways[u] %= mod;
        }
    }

    cout << ways[n-1] << "\n";

    return 0;
}

