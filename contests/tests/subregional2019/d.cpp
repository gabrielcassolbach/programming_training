#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
template<typename T> using arr = vector<T>;
template<typename T> using fun = function<T>;

const auto &_ = ignore;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    arr<arr<int>> adj(n);
    for(int i = 0; i < n-1; ++i) {
        int p;
        cin >> p;
        --p;
        adj[p].push_back(i+1);
    }
    arr<int> depth(n, 0), dir(n, -1);
    fun<void (int)> dfs_fill_data = [&](int u) {
        for(int v : adj[u]) {
            dfs_fill_data(v);
            if(depth[u] < depth[v]+1) {
                depth[u] = depth[v]+1;
                dir[u] = v;
            }
        }
    };
    dfs_fill_data(0);
    int res = 0;
    priority_queue<ii> q;
    q.push({depth[0], 0});
    fun<void (int)> dfs_arrest = [&](int u) {
        for(int v : adj[u]) {
            if(v == dir[u]) {
                dfs_arrest(v);
            } else {
                q.push({depth[v], v});
            }
        }
        res++;
    };
    while(!q.empty() && k--) {
        int u;
        tie(_, u) = q.top(), q.pop();
        dfs_arrest(u);
    }
    cout << res << '\n';
    return 0;
}
