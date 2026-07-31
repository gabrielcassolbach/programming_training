#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a, b; cin >> a >> b;
    vector<vector<int>> v; v.resize(a);
    int ans = 0;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){ 
            int val; cin >> val; 
            v[i].push_back(val);
        }
    }
    for(int j = 0; j < b; j++){
        int max_val = 0;
        for(int i = 0; i < a; i++){
            max_val = max(v[i][j], max_val);
        }
        ans += max_val;
    }
    cout << ans << "\n";
    return 0;
}

