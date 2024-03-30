#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

/*
7 7
7 2 9 2 6 5 9
9 1 10 7 1 4 9

*/

int main() {
    ll t, x, n, m, tot, ans;
    vector<ll> a, b;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        ans = 1e18;
        a.clear();
        b.clear();
        tot = 0;
        cin >> n >> m;
        for (ll j = 0; j < n; j++)
        {
            cin >> x;
            a.push_back(x);
        }
        for (ll j = 0; j < n; j++)
        {
            cin >> x;
            b.push_back(x);
        }
        for (ll j = n-1; j >= 0; j--) // m -> n  iajsdiajsd
        {
            if(j < m) {
                ans = min(tot + a[j], ans);
            }
            tot += min(a[j], b[j]);
        }
        cout << ans << endl;
    }
    return 0;
}