#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;

int main() { _
    ll b, l;
    vector<ll> v;
    cin >> b >> l;
    v.resize(l+10);
    for (ll i = 0; i < l; i++)
    {
        cin >> v[i];
    }
    bool par = l%2;
    ll val = 0;
    for (ll i = 0; i < l; i++)
    {
        
        if (par) {
            val = (val + v[i] + b+1) % (b+1);
        } else {
            val = (val - v[i] + b+1) % (b+1);
        }
        // cout << val << endl;
        par = !par;
    }

    if (val % (b+1) == 0) {
        cout << 0 << " " << 0 << endl;
        return 0;
    }


    ll n_par = val;
    ll n_impar = b+1-val;
    par = l%2;
    //cout << n_impar << " " << n_par << endl << endl;

    // cout << l << endl;
    for (ll i = 0; i < l; i++)
    {
        // cout << i <<" " << v[i] << endl;
        if (par) {
            if(v[i] >= n_par){
                cout << i + 1 << " " << v[i] - n_par << endl;
                return 0;
            }
        } else {
            if(v[i] >= n_impar){
                cout << i + 1 << " " << v[i] - n_impar << endl;
                return 0;
            }
        }
        par = !par;
    }

    cout << -1 << " " << -1 << endl;

    return 0;
}