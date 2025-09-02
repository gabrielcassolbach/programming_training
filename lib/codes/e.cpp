#include <bits/stdc++.h>
using namespace std;

// n -> 10^6.

typedef long long ll;

const ll inf = 1e16 + 7;
vector<ll> dp; 

ll rec(int n){
    if(n < 0) return inf;
    if(dp[n] != -1) return dp[n];
    if(n == 0) return 0;

    ll ans = 2ll*inf; int aux = n;

    while(aux){
        if(aux%10 != 0)
            ans = min(ans, rec(n - aux%10) + 1);
        aux /= 10;
    }

    return dp[n] = ans; 
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n; dp.resize(n + 1, -1); 
    cout << (rec(n) >= inf ? 0 : rec(n)) << "\n";
    return 0; 
}