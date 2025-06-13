#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define in insert

int main(){
    fastio; 
    int n; cin >> n;
    vector<vector<string>> v;
    map<string, int> m;
    set<string> names; 

    v.resize(n + 1); int idx = 1;
    for(int i = 0; i < n; i++) {
        string a, b; 
        cin >> a >> b; 
        if(a == b){
            cout << 1 << '\n';
            cout << a << '\n';
            return 0;
        }
        
        if(m[b] == 0)
            m[b] = idx++;
        
        v[m[b]].pb(a);
        names.in(b); 
    }

    set<string> ans; 
    for(auto it = names.begin(); it != names.end(); it++){
        if(v[m[*it]].size() > 1){
            for(int i = 0; i < v[m[*it]].size(); i++){
                if(names.find(v[m[*it]][i]) != names.end())
                    ans.in(v[m[*it]][i]);
            }
        }
    }

    cout << ans.size() << '\n';
    for(auto it = ans.begin(); it != ans.end(); ++it) cout << *it << "\n";
    return 0;
}
