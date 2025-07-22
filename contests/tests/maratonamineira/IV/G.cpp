#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;
template<typename T> using arr = vector<T>;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, x;
    cin >> n >> m >> x;
    arr<arr<ull>> adj(n, arr<ull>(n, 0));
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u][v] += w, adj[v][u] += w;
    }
    arr<arr<ull>> pow_adj(n, arr<ull>(n)), sum(n, arr<ull>(n));
    for(int i = 0; i < n; ++i) {
        copy(adj[i].begin(), adj[i].end(), pow_adj[i].begin());
        copy(adj[i].begin(), adj[i].end(), sum[i].begin());
    }
    auto add = [&](arr<arr<ull>> &a, const arr<arr<ull>> &b) {
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j) a[i][j] += b[i][j];
    };
    auto multiply = [&](arr<arr<ull>> &a, const arr<arr<ull>> &b) {
        arr<arr<ull>> res(n, arr<ull>(n, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j)
                for(int k = 0; k < n; ++k) res[i][j] += a[i][k]*b[k][j];
        }
        a = move(res);
    };
    for(int i = 2; i <= x; ++i) {
        multiply(pow_adj, adj);
        add(sum, pow_adj);
    }
    int t;
    cin >> t;
    while(t--) {
        int i, j;
        cin >> i >> j;
        --i, --j;
        cout << sum[i][j] << '\n';
    }
    return 0;
}
