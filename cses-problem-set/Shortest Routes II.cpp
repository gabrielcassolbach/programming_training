#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define graph vector<vector<pair<ll,ll>>> 
#define pb push_back

ll n, m, q;
graph g;

void setGraph(){
    cin >> n >> m >> q;
    while(m--){
        ll city1, city2, dist;  
        cin >> city1 >> city2 >> dist; 
        g[city1].pb({dist, city2});
    }   
}

void solve() {
    while(q--){
        ll p1, p2; cin >> p1 >> p2;
        

    }
}

int main() { _
    setGraph();
    solve();
    return 0;
}