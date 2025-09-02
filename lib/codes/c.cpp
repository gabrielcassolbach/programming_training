#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
vector<ll> dp, v; 

ll rec(int x){
    if(x < 0) return 0; 
    if(x == 0) return 1;
    if(dp[x] != -1) return dp[x];

    ll ans = 0; 
    for(int i = 0; i < (int) v.size(); i++)
        ans += rec(x - v[i])%mod;
    
    return dp[x] = ans%mod; 
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, x; cin >> n >> x; 
    v.resize(n); dp.resize(x + 1, -1);
    
    for(int i = 0; i < n; i++)
        cin >> v[i];

    cout << rec(x) << "\n";
    return 0; 
}