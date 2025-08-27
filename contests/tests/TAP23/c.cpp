#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool desc(ll v1, ll v2) {return v1 > v2;}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
  
    vector<ll> r(n), b(n), f(n, 0);
    for(int i = 0; i < n; i++) cin >> r[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    sort(r.begin(), r.end());
    sort(b.begin(), b.end(), desc);

    for(int i = 0; i < n; i++)
        f[i] = r[i] + b[i]; 
    
    sort(f.begin(), f.end());

    cout << f[f.size()-1] - f[0] << "\n";
    return 0;
}