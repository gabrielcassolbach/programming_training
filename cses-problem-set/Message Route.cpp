#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<bool> vis;
vector<int> dist;
vector<int> father;

void answer(){
    stack<int> path;
    if(dist[n] == -1) 
        {printf("IMPOSSIBLE\n"); return;}
    
    path.push(n); int node = father[n];
    while(node != 0)
        {path.push(node); node = father[node];}
    
    printf("%d\n", dist[n] + 1);
    while(!path.empty())
        {printf("%d ", path.top()); path.pop();}
    printf("\n");
}

void bfs(int v){
    vis[v] = true;
    queue<int> q; q.push(v);

    while(!q.empty()){
        int node = q.front(); q.pop();
        for(auto u : g[node]){
            if(!vis[u]){
                vis[u] = true; dist[u] = dist[node] + 1; father[u] = node;
                q.push(u);    
            }
        }
    }   
}

void init(){
    dist[1] = 0;
    for(int i = 2; i <= n; i++)
        {dist[i] = -1; vis[i] = false; father[i] = 0;}
}

void read(){
    scanf("%d %d", &n, &m);
    g.resize(n + 1); vis.resize(n + 1); dist.resize(n + 1); father.resize(n + 1);
    for(int i = 1; i <= m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

int main(){
    read();
    init();
    bfs(1);
    answer();
    return 0;
}