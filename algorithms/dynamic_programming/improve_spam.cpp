#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

int n, l; 
const int mod = 1e9 + 7;
vector<ll> dp, memo;
vector<vector<ll>> v; 

ll rec(int it){
    if(dp[it] != -1) return dp[it];
    ll ans = 0;
    for(auto val : v[it]){
        if(val <= l)
            ans += rec(val)%mod;
        else{    
            ans++;
            memo[val] = 1;
        }
    }
    return dp[it] = ans%mod;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> l; 
    dp.resize(l + 1, -1); // indexação de 1. 
    memo.resize(n + 1, 0);

    v.resize(l + 1);
    for(int i = 1; i <= l; i++){
        ll val; cin >> val;
        for(int j = 1; j <= val; j++){
            ll p; cin >> p;
            v[i].push_back(p);
        }
    }   
    ll b = rec(1);
    ll a = 0;
    for(int i = 1; i <= n; i++) a += memo[i];
    
    cout << b << " " << a << "\n";

    return 0;
}
