#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); 

int n, m;
vector<vector<int>> adj; 
vector<int> color, dist, ans, parent;

void set_graph(){
    adj.resize(n);
    color.assign(n, 0); 
    dist.assign(n, 0); 
    parent.assign(n, 0);

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

    for(int i = 0; i < ans.size(); i++){
        for(int u : adj[ans[i]]){

            if(dist[ans[i]] + 1 > dist[u]){
                dist[u] = dist[ans[i]] + 1;
                parent[u] = ans[i];   
            }
        }
    }
    
    if(dist[n-1] == 0) {cout << "IMPOSSIBLE\n"; return 0;}

    vector<int> path;
    int v = n-1;
    while(v != 0){
        path.push_back(v);
        v = parent[v];
    }
    path.push_back(0);
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for(int i = 0; i < (int) path.size(); i++) 
        cout << path[i] + 1 << ((path.size()-1 == i) ? "\n" : " "); 


    return 0;
}

