#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;
ll n; vector<ll> v;  

int main() { _
    cin >> n; v.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    ll cont = n; ll val = 0; ll ans = 0;
    for(int i = 0; i < n; i++){
        if(v[i] * cont > ans){
            val = v[i];
            ans = v[i] * cont;
        }
        cont--;
    }

    cout << val << " " << ans << endl;
    return 0;
}