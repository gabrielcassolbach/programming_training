#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    
    int ans = 0;
    while(n--){ 
        int val; cin >> val;
        ans += (val > 1) ? 1 : 0;
    }

    cout << ans << "\n";
    return 0;
}