#include <bits/stdc++.h>
using namespace std;

#define MAX 11234

using graph = vector<vector<int>>;
int vis[MAX];
int n, m, ans = 0;

void bfs(graph g, int v){
    printf("initial v: %d %d\n", v + 1, vis[v]);
    vis[v] = 1;
    
    queue<int> q; q.push(v);
    
    while(!q.empty()){
        int p = q.front(); q.pop();
    
        for(int j = 0; j < g[v].size(); j++){
            if(!vis[g[p][j]]) 
                {q.push(g[p][j]);}
            vis[g[p][j]] = 1;
        }
    }
    
}

void setComponents(graph g){
    for(int i = 0; i < n; i++)
        if(!vis[i])
            bfs(g, i);
}

void setGraph(graph g){
    int e1, e2;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &e1, &e2); --e1; --e2;
        g[e1].push_back(e2); g[e2].push_back(e1); 
    }   
    setComponents(g);
}

void init(){
    for(int i = 0; i < n; i++)
        vis[i] = 0;
}

int main(){
    scanf("%d %d", &n, &m);
    graph g(n);
    init();
    setGraph(g);
    printf("%d\n", ans);
    return 0;
}