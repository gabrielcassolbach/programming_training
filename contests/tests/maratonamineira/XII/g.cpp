#include <bits/stdc++.h>

using namespace std;

using ll = long long;
template<typename T> using arr = vector<T>;

ll const INF = 1e18L;

struct vert { int u, i; };
struct edg { vert v; int w; };

auto dijkstra(arr<arr<arr<edg>>> const &adj, vert src) {
    arr<arr<ll>> dist(adj.size(), arr<ll>(adj[0].size(), INF));
    using ll_ii = tuple<ll, int, int>;
    priority_queue<ll_ii, arr<ll_ii>, greater<ll_ii>> q;
    q.push({0, src.u, src.i});
    while(!q.empty()) {
        ll d;
        vert u;
        tie(d, u.u, u.i) = q.top();
        q.pop();
        if(dist[u.u][u.i] != INF) continue;
        dist[u.u][u.i] = d;
        for(edg e : adj[u.u][u.i]) q.push({d+e.w, e.v.u, e.v.i});
    }
    return [dist = move(dist)](vert u) { return dist[u.u][u.i]; };
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, c, p;
    cin >> n >> c >> p;
    arr<arr<arr<edg>>> adj(n, arr<arr<edg>>(3));
    for(int i = 0; i < c; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u][1].push_back({{v, 1}, w});
    }
    for(int i = 0; i < p; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u][0].push_back({{v, 0}, w}), adj[v][0].push_back({{u, 0}, w});
        adj[u][2].push_back({{v, 2}, w}), adj[v][2].push_back({{u, 2}, w});
    }
    for(int u = 0; u < n; ++u)
        adj[u][0].push_back({{u, 1}, 0}), adj[u][1].push_back({{u, 2}, 0});
    cout << dijkstra(adj, {0, 0})({n-1, 2}) << '\n';
    return 0; 
}
