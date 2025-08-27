#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll n; cin >> n;
    ll ans = 0;
    vector<ll> v(n); vector<ll> group(5);

    for(int i = 0; i < n; i++)
        {cin >> v[i]; group[v[i]%5]++;}

    for(int i = 0; i < 5; i++)
        cout << group[i] << " "; 
    cout << "\n";
    ans += group[0];
    ans += min(group[4], group[1]);
    ans += min(group[2], group[1]/3);
    ans += min(group[3], group[2]);
    ans += min(group[3], group[1]/2);

    cout << ans << "\n";
    return 0;
}