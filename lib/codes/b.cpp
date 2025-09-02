#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> dp, v; 
const ll INF = (1ll << 35);

ll rec(int x){
    if(x < 0) return INF;
    if(dp[x] != -1) return dp[x];
    if(x == 0) return 0; 

    ll ans = INF;
    for(int i = 0; i < (int) v.size(); i++){
        ans = min(ans, rec(x - v[i]) + 1); 
    }

    return dp[x] = ans;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, x; cin >> n >> x;

    v.resize(n); dp.resize((int)1e6 + 10, -1);
    for(int i = 0; i < n; i++) 
        cin >> v[i];

    ll ans = rec(x); 
    cout << (ans >= INF ? -1 : ans) << "\n";
    return 0; 
}