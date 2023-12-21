// Note: solution of Colin Galen
#include <bits/stdc++.h>
using namespace std;

#define MAX 500005

typedef long long ll;

ll n, m;
vector<ll> edges[MAX];
int vis[MAX], ans[MAX];

void bfs(){
    for(ll i = 0; i < n; i++){ 
        if(!vis[i]){
            vector<ll> component; queue<ll> q;  
            q.push(i);
            while(!q.empty()){
                ll x = q.front(); q.pop();
                if(vis[x]) continue; 
                
                vis[x] = 1; 
                component.push_back(x);
                
                for(ll y : edges[x])
                    if(!vis[y])
                        q.push(y);
            }
            for(ll x : component)
                ans[x] = component.size();
            component.clear();
        }
    }
}

void answer(){ 
    memset(vis, 0, sizeof(vis));
    bfs();
    for(ll i = 0; i < n; i++) 
        printf("%d ", ans[i]);
    printf("\n");
}

void read(){
    ll k; vector<ll> v;
    scanf("%lld %lld", &n, &m);
    for(ll i = 0; i < m; i++){
        scanf("%lld", &k);
        for(ll j = 0; j < k; j++){
            ll value; scanf("%lld", &value);
            v.push_back(--value);
        }
        for(ll j = 0; j + 1 < k; j++)
            {edges[v[j]].push_back(v[j + 1]); edges[v[j + 1]].push_back(v[j]);}
        v.clear();
    }
}

int main(){
    read();
    answer();   
    return 0;
}
