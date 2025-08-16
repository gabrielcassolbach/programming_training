#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    ll n; cin >> n;

    // dec to bin
    int one_counter = 0;

    while(n) {
        if(n % 2 == 1)
            one_counter++;

        n >>= 1;
    }

    // cout << one_counter << " 1s\n";

    ll ans = 1;
    while(one_counter--) {
        ans *= 2;
    }

    cout << ans << "\n";

    return 0;
}