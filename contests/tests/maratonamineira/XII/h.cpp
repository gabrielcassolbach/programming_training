#include <bits/stdc++.h>

using namespace std;

template<typename T> using arr = vector<T>;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    arr<int> w;
    arr<arr<int>> l(n);
    for(int i = 0; i < (1 << n); ++i) {
        int r;
        cin >> r;
        (r == 0 ? w : l[n-r]).push_back(i);
    }
    for(int i = 0; i < n; ++i) sort(l[i].begin(), l[i].end());
    bool ok = true;
    for(int i = 0; i < n && ok; ++i) {
        arr<int> ord(1 << i);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int a, int b) { return w[a] < w[b]; });
        arr<int> nw(1 << (i+1));
        for(int j = 0; j < (1 << i) && ok; ++j) {
            if(w[ord[j]] < l[i][j]) {
                nw[2*ord[j]] = w[ord[j]], nw[2*ord[j] + 1] = l[i][j];
            } else {
                ok = false;
            }
        }
        w = move(nw);
    }
    if(!ok) {
        cout << -1 << '\n';
    } else {
        for(int i = 0; i < (1 << n); ++i)
            cout << w[i]+1 << (i < (1 << n)-1 ? ' ' : '\n');
    }
    return 0; 
}
