#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

typedef long long ll;

ll n, m; 
vector<ll> edges[MAX];
bool vis[MAX];

void ans(){
    for(ll i = 0; i < n; i++){
        if(!vis[i]){
            

        }
    }
}

void set(){
    memset(vis, false, sizeof(vis));
}

void read(){
    scanf("%lld %lld", &n, &m);
    for(int i = 0; i < m; i++){
        ll k; scanf("%lld", &k);
        vector<ll> v; 
        for(ll j = 0; j < k; j++)
            {scanf("%lld", &v[j]); --v[j];}
        for(ll j = 0; j + 1 < k; j++){
            edges[v[j]].push_back(v[j + 1]);
            edges[v[j + 1]].push_back(v[j]);
        }       
    }
}

int main(){
    read();
    set();
    ans();
    return 0;
}