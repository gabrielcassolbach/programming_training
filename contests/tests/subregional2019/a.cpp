#include <bits/stdc++.h>

using namespace std;

template<typename T> using arr = vector<T>;
template<typename T> using fun = function<T>;

struct vec { int x, y; };

vec operator-(vec a, vec b) { return {a.x-b.x, a.y-b.y}; }

int dot(vec a, vec b) { return a.x*b.x + a.y*b.y; }

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int m, n, k;
    cin >> m >> n >> k;
    arr<vec> v(n);
    arr<int> s(n);
    for(int i = 0; i < k; ++i) cin >> v[i].x >> v[i].y >> s[i];
    auto intersect_circles = [&](int i, int j) {
        vec dv = v[j]-v[i];
        return dot(dv, dv) <= (s[i]+s[j])*(s[i]+s[j]);
    };
    auto intersect_low_right_wall = [&](int i) {
        return v[i].x+s[i] >= m || v[i].y-s[i] <= 0; 
    };
    auto intersect_upp_left_wall = [&](int i) {
        return v[i].x-s[i] <= 0 || v[i].y+s[i] >= n; 
    };
    arr<arr<bool>> adj(k+2, arr<bool>(k+2, false));
    for(int i = 0; i < k; ++i) {
        for(int j = i+1; j < k; ++j)
            if(intersect_circles(i, j)) adj[i][j] = adj[j][i] = true;
        if(intersect_low_right_wall(i)) adj[i][k] = adj[k][i] = true;
        if(intersect_upp_left_wall(i)) adj[i][k+1] = adj[k+1][i] = true;
    }
    arr<bool> vis(k+2, false);
    fun<bool (int, int)> dfs = [&](int u, int t) {
        if(vis[u]) return false;
        vis[u] = true;
        if(u == t) return true;
        for(int v = 0; v < k+2; ++v) {
            if(!adj[u][v]) continue;
            if(dfs(v, t)) return true;
        }
        return false;
    };
    cout << (dfs(k, k+1) ? 'N' : 'S') << '\n';
    return 0;
}
