#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); 

typedef long long ll;

#define WHITE 0
#define GRAY 1
#define BLACK 2

vector<vector<int>> adj; 
vector<int> color, vis, parent; 
int cycle_start, cycle_end; 
int n, m; 

void set_graph(){
    color.assign(n, WHITE);
    vis.assign(n, 0);
    parent.assign(n, -1);   
    adj.resize(n);

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[--a].push_back(--b);
    }
}

bool dfs(int v){
    color[v] = GRAY; 

    for(int u : adj[v]){
        if(color[u] == GRAY){
            cycle_start = u;
            cycle_end = v; 
            return true;
        }
        
        if(color[u] == WHITE){
            parent[u] = v;
            if(dfs(u)) return true;
        }
    }
    
    color[v] = BLACK;
    return false; 
}

int main(){
    fastio; cin >> n >> m; set_graph();
    cycle_start = cycle_end = -1;    
    
    bool has_cycle = false; 
    for(int v = 0; v < n && !has_cycle; v++)
        if(color[v] == WHITE)
            has_cycle = dfs(v);

    if(!has_cycle){
        cout << "IMPOSSIBLE\n";
        return 0; 
    }

    vector<int> path;     
    path.push_back(cycle_start);
    
    int v = cycle_end;
    
    while(v != cycle_start){
        path.push_back(v);
        v = parent[v];       
    }

    path.push_back(cycle_start);
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for(int i = 0; i < path.size(); i++)
        cout << path[i] + 1 << (i == (int)path.size()-1 ? "\n" : " ");

    return 0;
}