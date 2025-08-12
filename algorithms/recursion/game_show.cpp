#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int c; cin >> c;
    vector<int> memo, v;
    
    memo.resize(c, 0); v.resize(c);
    
    for(int i = 0; i < c; i++) cin >> v[i];
    
    memo[0] = v[0] + 100;
    for(int i = 1; i < (int) v.size(); i++) 
        memo[i] += memo[i-1] + v[i];
    
    int ans = 100;
    for(int i = 0; i < (int) v.size(); i++)
        ans = max(ans, memo[i]);
        

    cout << ans << "\n";

    return 0;
}