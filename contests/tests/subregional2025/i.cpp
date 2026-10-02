#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<ll> d; d.resize(n-1); 
    
    ll r = 1e14, l = -1e14; 

    // R is the set of all r values such that R < ...
    // L is the set of all l values such that R > ..

    // we only need the largest l and the minimum r.

    ll ai, bi; cin >> ai >> bi;
    for(int i = 0; i < n-1; i++){
        ll a, b; cin >> a >> b;
        d[i] = hypot(a - ai, b - bi);
        ai = a; bi = b;
    }

    ll c = 0;
    for(int i = 0; i < n-1; i++){
        if(i % 2 == 0){
            c += d[i];
            r = min(r, c);
        }else{
            c += d[i]*(-1);
            l = max(l, c);
        }
    }

    if(r - l >= 2 && r != 1)
        cout << r-1 << "\n";
    else 
        cout << -1 << "\n";

    return 0;
}