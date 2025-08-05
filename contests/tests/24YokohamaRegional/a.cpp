#include <bits/stdc++.h>

using namespace std;

template<typename T> using arr = vector<T>;
template<typename T> using fun = function<T>;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    arr<int> d(n);
    for(int i = 0; i < n; ++i) cin >> d[i];
    int res = 0;
    fun<void (int, int)> f = [&](int l, int r) {
        int m = *min_element(next(d.begin(), l), next(d.begin(), r));
        for(int i = l; i < r; ++i) {
            if(d[i] > m) {
                int j = i+1;
                while(j < r && d[j] > m) ++j;
                f(i, j);
                i = j-1;
            }
        }
        ++res;
    };
    f(0, n);
    cout << res << '\n';
    return 0;
}
