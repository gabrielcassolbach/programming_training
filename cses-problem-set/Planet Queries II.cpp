#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

int n, q; 
vector<vector<int>> adj, rev_adj; 
vector<int> node_type, dist, vis; // 0 is a node in a tree; 1 is a node in a cycle.
// 2 is a node in a different cycle and so on.  

void set_memo(){
    cin >> n >> q;
    adj.resize(n+1); rev_adj.resize(n+1);
    
    for(int i = 1; i <= n; i++){
        int val; cin >> val;
        adj[i].push_back(val);
        rev_adj[val].push_back(i);
    }
    
    node_type.resize(n + 1, -1);
    dist.resize(n + 1, 0);
    vis.resize(n + 1, 0);
}

void find_cycles_dfs(int node){
    vis[node] = 1;

    for(int u : adj[node]){
        if(vis[u] == 0)
            find_cycles_dfs(u);
        
        if(vis[u] == 1) 
            node_type[u] = 1;       
    }

    vis[node] = 2;
}

void mark_cycles_dfs(int node, vector<int> &cycle_ep, int cycle_counter){
    vis[node] = 1;
    node_type[node] = cycle_counter;
   
    if(rev_adj[node].size() > 1) cycle_ep.push_back(node);
    
    for(int u : adj[node])
        if(!vis[u])
            mark_cycles_dfs(u, cycle_ep, cycle_counter);
}

void set_dist_dfs(int node, int d){
    vis[node] = 1; dist[node] = d;
    
    for(int u : rev_adj[node]){
        if(!vis[u])
            set_dist_dfs(u, d+1);
    }
}

int main() {
    fastio;  
    set_memo();

    for(int i = 1; i <= n; i++)
        if(!vis[i])
            find_cycles_dfs(i);

    vis.assign(n+1, 0);
    
    vector<int> cycle_ep;
    int cycle_counter = 1;
    for(int i = 1; i <= n; i++)
        if(node_type[i] == 1)
            mark_cycles_dfs(i, cycle_ep, cycle_counter++);
            

    vis.assign(n+1, 0);
    for(int i = 0; i < (int) cycle_ep.size(); i++)
        set_dist_dfs(cycle_ep[i], 0);

    

    return 0;
}




