#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

/*
v = {1, 2, 3, 5, 7};

(4 % 15) == 4.
(4 % 10) == 4.
(4 % 6) == 4.
(4 % 3) == 1.

13 % 3 = 1.

ans += (13 - (13 % 3)) / 3;

// 5 4 3 2 1.
// 5 3 2 1.
// 5 3 1.
// 5 1.


*/

int main(){
    int t; cin >> t;
    int c[] = {1, 3, 6, 10, 15};     

    while(t--){
        ll n; cin >> n;
        ll ans = 0;
        for(int i = 4; i >= 0; i--){
            if(c[i] <= n){
                cout << c[i] << ' '; cout << endl;
                ans += ((n - (n % c[i])) / c[i]);
                n = (n % c[i]);
            }                
        }
        cout << ans << endl; 
    }
    return 0;
}