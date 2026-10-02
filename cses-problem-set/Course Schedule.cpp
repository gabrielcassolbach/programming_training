#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); 

int n, m, has_cycle; 
vector<vector<int>> adj; 
vector<int> color, ans; 

void set_graph(){
    adj.resize(n); color.assign(n, 0);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; 
        a--; b--;
        adj[a].push_back(b);
    }
}

void dfs(int v){
    color[v] = 1; 

    for(int u : adj[v]){
        if(color[u] == 1){
            has_cycle = true;
            return;
        }
        
        if(color[u] == 0)
            dfs(u);
    }
        
    color[v] = 2; 
    ans.push_back(v);
}

int main(){
    fastio; cin >> n >> m; set_graph();
    has_cycle = 0;
    
    for(int v = 0; v < n; v++)
        if(color[v] == 0) 
            dfs(v);

    
    if(has_cycle) {cout << "IMPOSSIBLE\n"; return 0;}

    reverse(ans.begin(), ans.end());

    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 << (ans.size()-1 == i ? "\n" : " ");
    
    return 0;
}


