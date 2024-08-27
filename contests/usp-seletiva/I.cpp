#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;

ll n; vector<ll> v;

void read(){
    cin >> n; v.resize(n + 10);
    for(int i = 0; i < n; i++) cin >> v[i];
}

ll solve(){
    set<ll> imp;
    ll has_p = 0; ll has_imp = 0; ll m_q1 = 0;
    for(int i = 0; i < n; i++){
        if(v[i] % ((ll)2)) {
            has_imp = 1;
            if(v[i] > 1) m_q1 = 1;
        }
        else if(v[i]) has_p = 1; 
    }
    return min((ll)2, has_p + has_imp + m_q1);
}

int main() { _
    read();
    cout << solve() << endl;
    return 0;
}