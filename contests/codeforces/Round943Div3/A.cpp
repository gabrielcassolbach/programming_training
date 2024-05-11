// A: Maximize.
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main(){
    int t, x; cin >> t;
    while(t--){
        cin >> x;
        int sum = 0, ans = 0; 
        for(int y = 1; y < x; y++){
            if((gcd(x, y) + y) > sum){
                sum = (gcd(x, y) + y);
                ans = y;
            }
        }
        cout << ans << endl;
    }
    return 0;
}