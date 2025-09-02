#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    const int mod = 1e9 + 7;

    int n, x; cin >> n >> x;    
    vector<ll> v, dp; 

    v.resize(n); dp.resize(x + 1, 0);
    
    for(int i = 0; i < n; i++)
        cin >> v[i];
 
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= x; j++){
            if(j - v[i] >= 0){
                dp[j] += dp[j - v[i]]; 
                dp[j] = dp[j]%mod;
            }
        }
    }

    cout << dp[x] << "\n";
    return 0; 
}