#include <bits/stdc++.h>
using namespace std;


int main(){ 
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n; 
    vector<int> v(n);

    for(int i = 0; i < n; i++)  
        cin >> v[i];

    vector<int> larger(n);
    larger[n-1] = v[n-1];
    for(int i = n-2; i >= 0; i--){
        larger[i] = max(v[i], larger[i+1]);
    }

    int ans = 0;
    for(int i = 0; i < n-1; i++)
        ans = max(ans, larger[i+1] - v[i]);

    cout << ans << "\n";
    
    return 0;
}