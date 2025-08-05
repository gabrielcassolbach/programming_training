#include <bits/stdc++.h>

using namespace std;

using ll = long long;
template<typename T> using arr = vector<T>;
template<typename T> using fun = function<T>;

struct vert { int i, j; };

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    arr<arr<char>> x(n, arr<char>(m));
    vert root = {-1, -1};
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> x[i][j];
            if(x[i][j] == 'P') root = {i, j};
        }
    }
    auto find_adj = [&](vert u, vert p) {
        arr<vert> mov = {{u.i-1, u.j}, {u.i, u.j-1}, {u.i, u.j+1},
                         {u.i+1, u.j}};
        arr<vert> res;
        for(vert v : mov) {
            if(v.i >= 0 && v.i < n && v.j >= 0 && v.j < m && x[v.i][v.j] != '.'
               && !(v.i == p.i && v.j == p.j))
            {
                res.push_back({v.i, v.j});
            }
        }
        return res;
    };
    fun<ll (vert, vert)> dfs = [&](vert u, vert p) {
        auto adj = find_adj(u, p);
        switch(x[u.i][u.j]) {
            case 'P':
            case '#':
                return dfs(adj[0], u);
            case '+':
                return dfs(adj[0], u)+dfs(adj[1], u);
            case '-': {
                ll a = dfs(adj[0], u), b = dfs(adj[1], u);
                if(a < b) swap(a, b);
                return a-b;
            }
            case '*':
                return dfs(adj[0], u)*dfs(adj[1], u);
            case '/': {
                ll a = dfs(adj[0], u), b = dfs(adj[1], u);
                if(a < b) swap(a, b);
                return a/b;
            }
            default:
                return (ll)(x[u.i][u.j]-'0');
        }
    };
    cout << dfs(root, {-1, -1}) << '\n';
    return 0;
}
