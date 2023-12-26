#include <bits/stdc++.h>
using namespace std;

int n, m;
bool impossible = false;
vector<vector<int>> g;
vector<bool> vis; 
vector<int> team;

void answer(){
    if(impossible) 
        {printf("IMPOSSIBLE\n"); return;}
    for(int i = 1; i <= n; i++)
        printf("%d ", team[i]);
    printf("\n");
}

void bfs(int v){
    vis[v] = true; team[v] = 1;
    
    queue<int> q; q.push(v);
    
    while(!q.empty()){
        int p = q.front(); q.pop();
        
        for(auto u : g[p]){
            if(!vis[u]){    
                if(team[p] == 1)
                    {team[u] = 2; vis[u] = true; q.push(u);} 
                else
                    {team[u] = 1; vis[u] = true; q.push(u);}
            }else{
                if(team[u] == team[p]) impossible = true;
            }
        }    
    }
}

void setTeams(){
    for(int i = 1; i <= n; i++)
        if(!vis[i])
            bfs(i);
}

void init(){
    for(int i = 1; i <= n; i++)
        vis[i] = false;
}

void read(){
    scanf("%d %d", &n, &m);
    g.resize(n + 1); vis.resize(n + 1); team.resize(n + 1);
    for(int i = 1; i <= m; i++){
        int a, b; scanf("%d %d", &a, &b);
        g[a].push_back(b); g[b].push_back(a);
    }
}

int main(){
    read();
    init();
    setTeams();
    answer();
    return 0;
}
