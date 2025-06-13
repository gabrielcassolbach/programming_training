#include <bits/stdc++.h>

using namespace std;

template<typename T> using arr = vector<T>;
template<typename T> using fun = function<T>;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    int root = -1;
    arr<arr<int>> adj(n);
    for(int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        if(p == -1) {
            root = i;
        } else {
            adj[p-1].push_back(i);
        }
    }
    arr<int> t(n);
    for(int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        t[b-1] = i;
    }
    arr<int> res(n);
    fun<void (int, int)> dfs_r = [&](int u, int p) {
        res[u] = p == -1 ? t[u] : min(t[u], res[p]);
        for(int v : adj[u]) dfs_r(v, u);
    };
    dfs_r(root, -1);
    for(int i = 0; i < n; ++i) cout << res[i]+1 << (i < n-1 ? ' ' : '\n');
    return 0;
}
