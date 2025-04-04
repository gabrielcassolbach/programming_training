#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back

int n;

struct event {
    int x;
    int idx;
    bool t;
};  

vector<event> v; 

bool ord (event e1, event e2) {
    return e1.x < e2.x || (e1.x == e2.x && (e1.t < e2.t));
}

void solve() {
    sort(v.begin(), v.end(), ord);
    int k = 0, cont = 0; 
    for(int i = 0; i < v.size(); i++){
        if(v[i].t == 0) cont++;
        else cont--;
        k = max(k, cont);
    }

    queue<int> q; 
    for(int i = 0; i < k; i++) q.push(i);

    vector<int> ans; ans.resize(n);
    for(int i = 0; i < v.size(); i++) {
        if(v[i].t == 0) {
            ans[v[i].idx] = q.front();            
            q.pop();
        }else{
            q.push(ans[v[i].idx]);
        }
    }
    cout << k << '\n';
    for(int i = 0; i < n; i++)  
        cout << ans[i] + 1 << " ";
    cout << '\n';
}

int main() {
    cin >> n; 
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.pb({a, i, 0}); v.pb({b, i, 1});
    }
    solve();
    return 0;
}