#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;

map<ll, pair<ll, ll>> m;
vector<ll> v;
ll n; 

void read(){
    cin >> n; v.resize(n + 10);
    for(int i = 0; i < n; i++) cin >> v[i]; 
}

void solve(){
    pair<ll, ll> p;
    ll ans = 1; ll max_elem = -1;
    for (int i = 0; i < n; i++)
    {
        if(m.count(v[i]) == 0) {
            m[v[i]] = {i,0};
        } else {
            p = m[v[i]];
            max_elem =  max(max_elem, p.first);
            p.second = p.first;
            p.first = i;
            m[v[i]] = p;
        }
        //cout << "max: " << max_elem << " i: " << i << endl;
        //cout<< v[i] << " " << m[v[i]].first << m[v[i]].second << endl;
        ans = max(ans, i - max_elem);
    }
    cout << ans << endl;
}   

int main(){
    _;
    read();
    solve();
    return 0;
}