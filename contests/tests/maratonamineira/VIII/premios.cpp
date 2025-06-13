#include <bits/stdc++.h>

using namespace std;

struct rec { int id, p, t; };

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<rec> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i].id >> v[i].p >> v[i].t;
    auto lt = [](rec l, rec r) {
        return l.p != r.p ? l.p > r.p : l.t < r.t;
    };
    sort(v.begin(), v.end(), lt);
    cout << v[k-1].id << '\n';
    return 0;
}
