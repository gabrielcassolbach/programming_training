#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

ll dp[19];

ll fat(int val){
    if(val == 0) return 1; 
    if(dp[val] != -1) return dp[val];
    return dp[val] = val*fat(val-1);
}

int main(){
    fastio;
    memset(dp, -1, sizeof dp);
    fat(18);
    int n, m, p, s; cin >> n >> m >> p >> s; 
    ll ans = p*s; 
    while(m--){
        int a, b; cin >> a >> b; 
        

    }
    return 0;
}