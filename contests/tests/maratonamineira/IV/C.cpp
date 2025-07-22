#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int k;
    cin >> k;
    while(k--) {
        int n;
        ll q;
        cin >> n >> q;
        if(q > (ll)n*(n+1)/2) {
            cout << "IMPOSSIVEL\n";
            continue;
        }
        int l = 1, r = n+1;
        while(l < r) {
            int m = (l+r)/2;
            if(q >= (ll)(m+n)*(n-m+1)/2) {
                r = m;
            } else {
                l = m+1;
            }
        }
        cout << (n-r+1)+(q > (ll)(r+n)*(n-r+1)/2) << '\n';
    }
    return 0;
}
