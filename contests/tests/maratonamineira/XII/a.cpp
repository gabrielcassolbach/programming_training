#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
template<typename T> using arr = vector<T>;

struct cmp {
    bool operator()(ii a, ii b) {
        int da = (a.second-a.first-1)/2, db = (b.second-b.first-1)/2;
        return da != db ? da < db : a.first > b.first;
    };
};

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    arr<int> res(n);
    res[0] = 0;
    if(n >= 2) res[n-1] = 1;
    if(n >= 3) {
        priority_queue<ii, arr<ii>, cmp> q;
        q.push({1, n-1});
        for(int i = 2; i < n; ++i) {
            auto [l, r] = q.top();
            q.pop();
            int m = (l+r)/2;
            if(((r-l) & 1) == 0) --m;
            res[m] = i;
            if(m-l >= 1) q.push({l, m});
            if(r-m-1 >= 1) q.push({m+1, r});
        }
    }
    for(int i = 0; i < n; ++i) cout << res[i]+1 << (i < n-1 ? ' ' : '\n');
    return 0; 
}
