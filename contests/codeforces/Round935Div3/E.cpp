#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

vector<ll> v;
ll n, x, tmp;

ll binary(ll r, ll l, ll x) {
    if((r-l) == 1) return l;
    ll m = (r+l)/2;
    if(v[m] <= x) 
        return binary(r, m, x);
    else
        return binary(m, l, x);
}

void read(){
    v.clear();
    cin >> n >> x;
    v.resize(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
}

int main(){
    int t; cin >> t;
    while(t--){
        read();
        ll pos = binary(n-1, 0, x); 
        cout << pos + 1 << endl;
    }
    return 0;
}