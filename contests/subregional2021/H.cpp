#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;

ll n, k; vector<vector<ll>> v; vector<ll> colors;
vector<ll> ans;

void read(){
    cin >> n >> k;
    v.resize(n + 10); colors.resize(n + 10);
    for(int i = 1; i <= n; i++){
        ll pos, clr; cin >> pos >> clr;
        colors[i] = clr;
        v[clr].push_back(pos);
    }
    // for(int i = 1; i <= n; i++){
    //     cout << "i: " << i << endl;
    //     for(auto it = v[i].begin(); it != v[i].end(); it++){
    //         cout << (*it) << " ";
    //     }
    //     cout << endl;

    // }
    for(int i = 1; i <= n; i++){
        sort(v[i].begin(), v[i].end());
    }
}

char solve() {
    for(int i = 1; i <= n; i++){
        auto it = v[colors[i]].begin();
        ans.push_back(*it);
        v[colors[i]].erase(it);
    }
    ll answer = 1;
    for(int i = 1; i < ans.size(); i++){
        //cout << ans[i] << endl;
        if(ans[i] < ans[i-1]) answer = 0;
    }
    return answer == 0 ? 'N' : 'Y';
}


int main() { _
    read();
    cout << solve() << endl;
    return 0;
}