#include <bits/stdc++.h>

using namespace std;

template<typename T> using arr = vector<T>;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    map<int, int> cnt;
    for(int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++cnt[a];
    }
    if(cnt[2*2*2*269*7487]) {
        cout << 1 << '\n';
        cout << 2*2*2*269*7487 << '\n';
    } else if(cnt[2] && cnt[2*2*269*7487]) {
        cout << 2 << '\n';
        cout << 2 << ' ' << 2*2*269*7487 << '\n';
    } else if(cnt[269] && cnt[2*2*2*7487]) {
        cout << 2 << '\n';
        cout << 269 << ' ' << 2*2*2*7487 << '\n';
    } else if(cnt[7487] && cnt[2*2*2*269]) {
        cout << 2 << '\n';
        cout << 7487 << ' ' << 2*2*2*269 << '\n';
    } else if(cnt[4] && cnt[2*269*7487]) {
        cout << 2 << '\n';
        cout << 4 << 2*269*7487 << '\n';
    } else if(cnt[2*269] && cnt[2*2*7487]) {
        cout << 2 << '\n';
        cout << 2*269 << ' ' << 2*2*7487 << '\n';
    } else if(cnt[2*7487] && cnt[2*2*269]) {
        cout << 2 << '\n';
        cout << 2*7487 << ' ' << 2*2*269 << '\n';
    } else if(cnt[269*7487] && cnt[8]) {
        cout << 2 << '\n';
        cout << 269*7487 << ' ' << 8 << '\n';
    } else if(cnt[2] >= 2 && cnt[2*269*7487]) {
        cout << 3 << '\n';
        cout << 2 << ' ' << 2 << ' ' << 2*269*7487 << '\n';
    } else if(cnt[2] && cnt[269] && cnt[2*2*7487]) {
        cout << 3 << '\n';
        cout << 2 << ' ' << 269 << ' ' << 2*2*7487 << '\n';
    } else if(cnt[2] && cnt[7487] && cnt[2*2*269]) {
        cout << 3 << '\n';
        cout << 2 << ' ' << 7487 << ' ' << 2*2*269 << '\n';
    } else if(cnt[269] && cnt[7487] && cnt[8]) {
        cout << 3 << '\n';
        cout << 269 << ' ' << 7487 << ' ' << 8 << '\n';
    } else if(cnt[2] && cnt[4] && cnt[269*7487]) {
        cout << 3 << '\n';
        cout << 2 << ' ' << 4 << ' ' << 269*7487 << '\n';
    } else if(cnt[2] && cnt[2*269] && cnt[2*7487]) {
        cout << 3 << '\n';
        cout << 2 << ' ' << 2*269 << ' ' << 2*7487 << '\n';
    } else if(cnt[269] && cnt[4] && cnt[2*7487]) {
        cout << 3 << '\n';
        cout << 269 << ' ' << 4 << ' ' << 2*7487 << '\n';
    } else if(cnt[7487] && cnt[4] && cnt[2*269]) {
        cout << 3 << '\n';
        cout << 7487 << ' ' << 4 << ' ' << 2*269 << '\n';
    } else if(cnt[2] >= 3 && cnt[269*7487]) {
        cout << 4 << '\n';
        cout << 2 << ' ' << 2 << ' ' << 2 << ' ' << 269*7487 << '\n';
    } else if(cnt[2] >= 2 && cnt[269] && cnt[2*7487]) {
        cout << 4 << '\n';
        cout << 2 << ' ' << 2 << ' ' << 269 << ' ' << 2*7487 << '\n';
    } else if(cnt[2] >= 2 && cnt[7487] && cnt[2*269]) {
        cout << 4 << '\n';
        cout << 2 << ' ' << 2 << ' ' << 7487 << ' ' << 2*269 << '\n';
    } else if(cnt[2] && cnt[269] && cnt[7487] && cnt[4]) {
        cout << 4 << '\n';
        cout << 2 << ' ' << 269 << ' ' << 7487 << ' ' << 4 << '\n';
    } else if(cnt[2] >= 3 && cnt[269] && cnt[7487]) {
        cout << 5 << '\n';
        cout << 2 << ' ' << 2 << ' ' << 2 << ' ' << 269 << ' ' << 7487 << '\n';
    } else {
        cout << 0 << '\n';
    }
    return  0;
} 
