#include <bits/stdc++.h>

using namespace std;

template<typename T> using arr = vector<T>;

const auto &_ = ignore;
const string CARD = "A23456789DQJK";

struct player {
    arr<int> cnt;
    map<int, set<int>> cards_by_cnt;
    bool has_wildcard;
};

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    arr<player> p(n, {arr<int>(14, 0), {}, false});
    map<char, int> value;
    for(int i = 0; i < 13; ++i) value[CARD[i]] = i+1;
    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for(char ch : s) ++p[i].cnt[value[ch]];
        for(int j = 1; j < 14; ++j)
            if(p[i].cnt[j] > 0) p[i].cards_by_cnt[p[i].cnt[j]].insert(j);
    }
    auto has_win_state = [&](int i) {
        return p[i].cards_by_cnt.rbegin()->first == 4;
    };
    for(int i = 0; i < n; ++i) {
        if(has_win_state(i)) {
            cout << i+1 << '\n';
            return 0;
        }
    }
    int i = k-1;
    p[i].has_wildcard = true;
    while(!has_win_state(i)) {
        auto it = p[i].cards_by_cnt.begin();
        int cnt = it->first, val = *(it->second.begin());
        p[i].cards_by_cnt[cnt].erase(val);
        --p[i].cnt[val];
        if(cnt > 1) p[i].cards_by_cnt[cnt-1].insert(val);
        if(val == 0) {
            p[(i+1)%n].has_wildcard = true;
        } else {
            if(p[(i+1)%n].cnt[val] > 0)
                p[(i+1)%n].cards_by_cnt[p[(i+1)%n].cnt[val]].erase(val);
            p[(i+1)%n].cards_by_cnt[++p[(i+1)%n].cnt[val]].insert(val);
        }
        if(p[i].has_wildcard) {
            p[i].has_wildcard = false;
            p[i].cards_by_cnt[++p[i].cnt[0]].insert(0);
        }
        i = (i+1)%n;
    }
    cout << i+1 << '\n';
    return 0;
}
