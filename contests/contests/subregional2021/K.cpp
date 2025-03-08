#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;

int main() { _
    ll t, d, m; cin >> t >> d >> m;
    vector<ll> v; v.resize(m + 10);
    v[0] = 0;
    for(int i = 1; i <= m; i++){
        cin >> v[i];
    }
    v[m+1] = d; 
  
    for(int i = 1; i <= m+1; i++){
        if(v[i] - v[i-1] >= t) {cout << "Y" << endl; return 0;}
    }
    cout << "N" << endl; 
    return 0;
}