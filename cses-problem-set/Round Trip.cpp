#include <bits/stdc++.h>
using namespace std;

int n, m;
bool found = false; 
vector<vector<int>> g;
vector<bool> vis; vector<int> path;

void printAnswer(int node){
    bool stop = false; vector<int> p;
    
    for(int i = (int) path.size() - 1; i >= 0 && !stop; i--){
        p.push_back(path[i]);
        if(i < (int) path.size() - 1 && path[i] == node)
            stop = true; 
    }

    printf("%d\n", (int) p.size());
    for(int i = 0; i < (int) p.size(); i++)
        printf("%d ", p[i]);
    printf("\n");
}

void dfs(int node, int parent){
    if(found) return;
    
    if(vis[node] && path.size() > 2)
        {path.push_back(node); printAnswer(node); found = true; return;}
    

    vis[node] = true;
    path.push_back(node);

    for(auto child : g[node])
        if(!(child == parent))
            dfs(child, node);

    path.pop_back();
}

void findCycle(){
    for(int i = 1; i <= n; i++)
        if(!vis[i])
            dfs(i, -1);
}

void read(){
    scanf("%d %d", &n, &m);
    g.resize(n + 1); vis.resize(n + 1);
    for(int i = 1; i <= m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b); 
        g[b].push_back(a);
    }
}

int main(){
    read(); 
    findCycle();
    if(!found)
        printf("IMPOSSIBLE\n");
    return 0;
}