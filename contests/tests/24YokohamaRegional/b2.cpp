#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    ll a, b;
    cin >> a >> b;
    ll pref = 0;
    for(int i = 59; i >= 0 && (a & (1ll << i)) == (b & (1ll << i)); --i)
        pref |= a & (1ll << i);
    a ^= pref, b ^= pref;
    if(a == 0) {
        cout << pref << '\n';
    } else {
        ll suff = 1ll << (64-1-__builtin_clzll(a));
        if(suff != a) suff <<= 1;
        cout << (pref | suff) << '\n';
    }
    return 0;
}
