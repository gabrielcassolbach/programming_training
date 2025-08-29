#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;

    vector<int> v(n); 
    
    for(int i = 0; i < n; i++) 
        cin >> v[i];

    sort(v.begin(), v.end());

    int ans = 0;
    for(int i = 1; i < n; i++)
        ans += v[i] - v[0];
    
    cout << ans << "\n";

    return 0;
}