#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); 

int n, x; 
vector<int> v;
map<int, vector<int>> m;

void solve() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            ll sum = v[i] + v[j];
            if(sum >= x) continue;
            if(m.find(x-sum) == m.end()) continue;  
            for(int idx : m[x-sum]){
                if(idx != i && idx != j){
                    cout << ++i << " " << ++j << " " << ++idx << '\n';
                    return;
                }
            }        
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    fastio;
    cin >> n >> x; 
    v.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        m[v[i]].push_back(i);
    }
    solve();
    return 0;
}