#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back

vector<vector<int>> g; 
vector<int> vis;
vector<char> sep; 
int n, m; 

void set_g(){
    g.resize(n + 1); vis.resize(n + 1, 0); sep.resize(n + 1, 'A');
    for(int i = 1; i <= m; i++){
        int a, b; cin >> a >> b;
        g[a].pb(b); g[b].pb(a);
    }
}

void dfs(int node){
    vis[node] = true; 
    for(auto u : g[node])
        if(!vis[u] && u != n)
            dfs(u);
    sep[node] = 'B';
}

int main() {
    fastio;
    cin >> n >> m; 
    set_g();
    dfs(n-1);
    for(int i = 1; i <= n; i++)
        cout << sep[i];
    cout << '\n';
    return 0;
}