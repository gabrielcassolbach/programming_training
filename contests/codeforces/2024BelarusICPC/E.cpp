#include <bits/stdc++.h>

using namespace std;

template<typename T> using arr = vector<T>;
template<typename T> using fun = function<T>;

auto dfs(arr<int> &a, const arr<arr<int>> &adj, int src) {
    bool possible = true;
    arr<int> tour;
    fun<void (int, int)> dfs_r = [&](int u, int p) {
        tour.push_back(u);
        for(int v : adj[u]) {
            if(v == p) continue;
            --a[v], dfs_r(v, u), --a[u], tour.push_back(u);
            if(!possible) return;
            if(a[v] > 0 && a[v] > a[u]) {
                possible = false;
                return;
            } else {
                for(int i = 0; i < a[v]; ++i)
                    tour.push_back(v), tour.push_back(u);
                a[u] -= a[v], a[v] = 0;
            }
        }
    };
    dfs_r(src, -1);
    for(int e : a) possible &= e == 0;
    return make_pair(possible, tour);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    arr<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    arr<arr<int>> adj(n);
    for(int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v), adj[v].push_back(u);
    }
    auto [possible, res] = dfs(a, adj, 0);
    if(!possible) {
        cout << 0 << '\n';
    } else {
        for(auto it = res.begin(); it != res.end(); ++it)
            cout << *it + 1 << (next(it) != res.end() ? ' ' : '\n');
    }
    return 0;
}
