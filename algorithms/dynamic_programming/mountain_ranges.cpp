#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, x; cin >> n >> x; 

    vector<int> v(n);
    for(int i = 0; i < n; i++)  
        cin >> v[i];

    int seq = 1, ans = 1; 
    for(int i = 1; i < n; i++){
        if((v[i] - v[i-1]) <= x)
            seq++;
        else
            seq = 1;
        ans = max(ans, seq);
    }


    cout << ans << "\n";

    return 0;
}