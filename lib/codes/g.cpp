#include <bits/stdc++.h>
using namespace std;

struct book {
    int h, s;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, lim;
    cin >> n >> lim;
    vector<book> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].h;
    for (int i = 0; i < n; i++) cin >> v[i].s;

    vector<int> dp(lim + 1, 0);

    for (int i = 0; i < n; i++) 
        for (int cap = lim; cap >= v[i].h; cap--) 
            dp[cap] = max(dp[cap], dp[cap - v[i].h] + v[i].s);

    cout << dp[lim] << "\n";
    return 0;
}