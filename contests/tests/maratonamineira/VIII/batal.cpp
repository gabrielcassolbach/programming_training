#include <bits/stdc++.h>

using namespace std;

using ll = long long;
template<typename T> using arr = vector<T>;

struct vec { int x, y; };

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    arr<vec> evs(q);
    for(int i = 0; i < q; ++i) {
        cin >> evs[i].x >> evs[i].y;
        --evs[i].x, --evs[i].y;
    }
    auto lt_xy = [](vec l, vec r) {
        return l.x != r.x ? l.x < r.x : l.y < r.y;
    };
    auto lt_yx = [](vec l, vec r) {
        return l.y != r.y ? l.y < r.y : l.x < r.x;
    };
    ll res = 0;
    sort(evs.begin(), evs.end(), lt_xy);
    for(int i = 0, it = 0; i < n; ++i) {
        int prev = -1;
        while(it < q && evs[it].x == i) {
            int len = evs[it].y-prev-1;
            res += (ll)len*(len+1)/2;
            prev = evs[it].y;
            ++it;
        }
        int len = n-prev-1;
        res += (ll)len*(len+1)/2;
    }
    sort(evs.begin(), evs.end(), lt_yx);
    for(int j = 0, it = 0; j < n; ++j) {
        int prev = -1;
        while(it < q && evs[it].y == j) {
            int len = evs[it].x-prev-1;
            res += (ll)len*(len-1)/2;
            prev = evs[it].x;
            ++it;
        }
        int len = n-prev-1;
        res += (ll)len*(len-1)/2;
    }
    cout << res << '\n';
    return 0;
}
