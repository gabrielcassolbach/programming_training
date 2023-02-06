#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

int n, nei[MAX], vis[MAX]; 
map<string, int> s2v;

int dfs (int u, int l){
    if(vis[u]) return vis[u] == 1;
    vis[u] = 1;
    return dfs(nei[u], 1);
}

int main(){
    int u, v, ans = 0;
    char str1[20], str2[20]; 
    n = 0;
    // Criação do Grafo.
    while(scanf(" %s %s", str1, str2) != EOF){
        string s1(str1), s2(str2);
        u = s2v.find(s1) == s2v.end() ? n++ : s2v[s1];
        v = s2v.find(s2) == s2v.end() ? n++ : s2v[s2];
        nei[u] = v;
    }
    memset(vis, 0, sizeof(vis));
    for(u = 0; u < n; u++) ans += dfs(u, u + 1);
    printf("%d\n", ans);
    return 0;
}