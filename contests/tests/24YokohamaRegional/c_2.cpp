#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ll_i = pair<ll, int>;
template<typename T> using arr = vector<T>;
template<typename T> using fun = function<T>;

struct edg { int v, w; };

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    arr<int> p(n);
    for(int i = 0; i < n; ++i) cin >> p[i];
    arr<arr<edg>> adj(n);
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].push_back({v, w}), adj[v].push_back({u, w});
    }
    ll res = 0;
    arr<ll> dist(n, -1);
    priority_queue<ll_i, arr<ll_i>, greater<ll_i>> q;
    q.push({0, 0});
    while(!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        if(dist[u] != -1) continue;
        dist[u] = d;
        res += d*p[u];
        for(edg e : adj[u]) q.push({d+e.w, e.v});
    }
    cout << res << '\n';
    return 0;
}
