#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

string solve(){
    vector<ll> a, b; 
    int n; cin >> n;
    a.resize(n); b.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    ll ai, bi; ai = bi = 0;
    for(int i = 0; i < n; i++){
        ai += a[i];
        bi += b[i];
        if(ai > bi) return "NO";
    }
    return "YES";
}

int main() {
    int t; cin >> t;
    while(t--){ 
        cout << solve() << "\n";
    }
    return 0;
}