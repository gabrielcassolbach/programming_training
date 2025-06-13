#include <bits/stdc++.h>

using namespace std;

template<typename T> using arr = vector<T>;

auto build_spt(const arr<arr<int>> &x) {
    int n = x.size(), m = x[0].size();
    arr<arr<arr<int>>> mem(10, arr<arr<int>>(n, arr<int>(m)));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) mem[0][i][j] = x[i][j];
    for(int e = 1; e < 10; ++e) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(i+(1 << (e-1)) >= n || j+(1 << (e-1)) >= m) continue;
                mem[e][i][j] = mem[e-1][i][j]
                               | mem[e-1][i+(1 << (e-1))][j]
                               | mem[e-1][i][j+(1 << (e-1))]
                               | mem[e-1][i+(1 << (e-1))][j+(1 << (e-1))];
            }
        }
    }
    auto query_spt = [mem = move(mem)](int l, int i, int j) {
        int e = 32-__builtin_clz(l)-1;
        return mem[e][i][j] | mem[e][i+l-(1 << e)][j]
               | mem[e][i][j+l-(1 << e)] | mem[e][i+l-(1 << e)][j+l-(1 << e)];
    };
    return query_spt;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, t;
    cin >> n >> m >> t;
    arr<arr<int>> x(n, arr<int>(m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) cin >> x[i][j];
    }
    auto spt = build_spt(x);
    int res_l = -1, res_i = -1, res_j = -1;
    auto search_square = [&](int l) {
        for(int i = 0; i <= n-l; ++i) {
            for(int j = 0; j <= m-l; ++j) {
                if((spt(l, i, j) & ((1 << t)-1)) == (1 << t)-1) {
                    res_l = l, res_i = i, res_j = j;
                    return true;
                }
            }
        }
        return false;
    };
    int a = 1, b = min(n, m)+1;
    while(a < b) {
        int m = (a+b)/2;
        if(search_square(m)) {
            b = m;
        } else {
            a = m+1;
        }
    }
    if(res_l == -1) {
        cout << -1 << '\n';
    } else {
        cout << res_l*res_l << '\n' << res_i << ' ' << res_j << '\n';
    }
    return 0;
}
