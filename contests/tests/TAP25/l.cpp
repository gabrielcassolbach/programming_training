#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
vector<ll> v, p_sum;
vector<vector<ll>> dp;
ll n, g; 

ll rec(ll k, ll i){
    if((i + k) > n) return 0;
    if(i == n + 1) return 0; 
    if(dp[k][i] != -1) return dp[k][i];

    ll op1 = rec(k, i+1);
    ll op2 = rec(k+1, i+k+1) +  g - (p_sum[i+k] - p_sum[i-1]);
    
    return dp[k][i] = max(op1, op2);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> g; 
    v.resize(n+1), p_sum.resize(n+1); 
    dp.resize(1000, vector<ll> (n + 1, -1));

    for(int i = 1; i <= n; i++)
        cin >> v[i];
    
    p_sum[0] = 0;
    for(int i = 1; i <= n; i++)
        {p_sum[i] += p_sum[i-1] + v[i];}  

    cout << rec(0, 1) << "\n";
    return 0; 
}