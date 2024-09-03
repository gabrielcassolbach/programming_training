#include <bits/stdc++.h>
using namespace std;
 
#define MAX 112345

int n, m;
int cc = -1;
vector<vector<int>> g;
vector<bool> vis;
vector<int> lead;
 
void dfs(int u){
    vis[u] = true;
    for(auto v: g[u])
        if(!vis[v])
            dfs(v);
}
 
void setComponents(){
    for(int i = 0; i < n; i++)
        if(!vis[i])
            {cc++; lead.push_back(i); dfs(i);}
}
 
void setGraph(){
    int e1, e2;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &e1, &e2); --e1; --e2;
        g[e1].push_back(e2); g[e2].push_back(e1); 
    }   
    setComponents();
}
 
void init(){
    g.resize(n); vis.resize(n);
    for(int i = 0; i < n; i++)
        vis[i] = 0;
}
 
void answer(){
    printf("%d\n", cc);
    if(lead.size() == 1) return;
    for(int i = 1; i < lead.size(); i++)
        printf("%d %d\n", lead[i-1] + 1, lead[i] + 1);
}
 
int main(){
    scanf("%d %d", &n, &m);
    init();
    setGraph();
    answer();
    return 0;
}
