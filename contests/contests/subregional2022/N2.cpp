#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;

int main() { _
    ll n, k, l; cin >> n; 
    vector<ll> cima, baixo; 
    cima.resize(n + 10); baixo.resize(n + 10);
    for(int i = 0; i < n; i++) cin >> cima[i];
    for(int i = 0; i < n; i++) cin >> baixo[i];
    cin >> k >> l;

    ll ans = 0; 
    multiset<ll> s;
    multiset<ll> mai;  multiset<ll> men; 

    ll tmp_ans = 0; 
    for(int i = n-k; i < n; i++){
        tmp_ans += cima[i];
        s.insert(baixo[i]);
    }
    auto it = --s.end();
    for(int i = 0; i < l; i++){
        tmp_ans += (*it); 
        --it;
    }

    for(int i = 0; i < n-1; i++){   
        tmp_ans += (cima[i] - cima[(n-k+i) % n]);





        ans = max(tmp_ans, ans);
    }

    cout << ans << endl;

    return 0;
}
