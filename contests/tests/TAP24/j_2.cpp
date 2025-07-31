#include <bits/stdc++.h>
using namespace std;

vector<int> v;
map<int, int> m;
int n, x;
vector<pair<int, int>> ans;

bool solve() {
    for(auto e : m) ans.push_back(e);
    if(m.size() == 2 && m.begin()->first+m.rbegin()->first == x) return false;
    for(int i = 1; i < (int)ans.size(); ++i) {
        if(ans[i].first+ans[i-1].first == x) {
            if(i > 1) {
                swap(ans[i-1], ans[0]);
            } else {
                swap(ans[i], ans[ans.size()-1]);
            }
            break;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        int val; cin >> val;
        m[val]++; 
    }

    if((x & 1) == 0 && m.find(x/2) != m.end()) {
        int cnt_hx = m[x/2];
        m.erase(x/2);
        if(n-cnt_hx < cnt_hx-1) {
            cout << "*\n";
        } else {
            if(!solve() && m[0] >= cnt_hx) {
                ans.insert(next(ans.begin(), m[0]), {x/2, 1});
                cnt_hx--;
            }
            bool first = true;
            for(auto [val, cnt] : ans) {
                for(int i = 0; i < cnt; ++i) {
                    if(cnt_hx-- > 0)
                        cout << (first ? (first = false, "") : " ") << x/2;
                    cout << (first ? (first = false, "") : " ") << val;
                }
            }
            if(cnt_hx-- > 0) cout << (first ? (first = false, "") : " ") << x/2;
            cout << '\n';
        }
    } else {
        if(solve()) {
            bool first = true;
            for(auto [val, cnt] : ans) {
                for(int i = 0; i < cnt; ++i) 
                    cout << (first ? (first = false, "") : " ") << val;
            }
            cout << '\n';
        } else {
            cout << "*\n";
        }
    }
    
    return 0;
}
