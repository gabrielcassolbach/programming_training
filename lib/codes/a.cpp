#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
vector<ll> dp; 

ll rec(int n){
    if(n < 0) return 0;
    if(dp[n] != -1) return dp[n];
    if(n == 0) return 1; 
    

    ll ans = 0;
    for(int i = 1; i <= 6; i++)
        ans += rec(n-i)%mod;

    return dp[n] = ans%mod; 
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n; dp.resize(n + 1, -1); 
    cout << rec(n) << "\n";
    return 0; 
}