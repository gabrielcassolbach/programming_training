#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 998244353;

int n, k;
vector<vector<int>> dp_mem, suff_sum_mem;

/*
4:

4
(3 1)
2 2
2 1 1
1 1 1 1

dp(4, 1) = 2: 2 1 1, 1 1 1 1
dp(4, 2) = 1: 2 2
dp(4, 3) = 0
dp(4, 4) = 1: 4

*/

int suff_sum(int, int);

int dp(int n, int m) {
    if(dp_mem[n][m] != -1) return dp_mem[n][m];
    if(m == k) return dp_mem[n][m] = 0;
    if(n == m) return dp_mem[n][m] = 1;
    return dp_mem[n][m] = suff_sum(n-m, m);
}

int suff_sum(int n, int m) {
    if(n < m) return 0;
    if(suff_sum_mem[n][m] != -1) return suff_sum_mem[n][m];
    return suff_sum_mem[n][m] = (dp(n, m)+suff_sum(n,m+1))%MOD;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> k;
    dp_mem.resize(n+1, vector<int>(n+1, -1));
    suff_sum_mem.resize(n+1, vector<int>(n+1, -1));

    int res = 0;
    for(int i = 1; i <= n; ++i) res = (res+dp(n, i))%MOD;
    cout << res << '\n';

    return 0;
}