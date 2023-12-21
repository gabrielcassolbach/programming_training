// Note: solution of Colin Galen.
#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

typedef long long ll;

ll n, m; ll c[MAX];
vector<ll> edges[MAX];
int vis[MAX];

ll dfs(ll v){ 
    vis[v] = 1;
    ll cost = c[v];
    for(ll x: edges[v]) 
        if(!vis[x])
            cost = min(cost, dfs(x));
    return cost;
}

void setVis(){
    for(ll i = 0; i < n; i++) 
        vis[i] = 0; 
}

void ans(){
    setVis();   
    ll answer = 0;
    for(ll i = 0; i < n; i++){ 
        if(!vis[i])
            answer += dfs(i);
    }
    printf("%lld\n", answer);
}

void read(){
    scanf("%lld %lld", &n, &m);
    for(ll i = 0; i < n; i++) 
        scanf("%lld", &c[i]);
    for(ll i = 0; i < m; i++){
        ll u, v; 
        scanf("%lld %lld", &u, &v);
        --u; --v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
}

int main(){
    read();
    ans();
    return 0;
}