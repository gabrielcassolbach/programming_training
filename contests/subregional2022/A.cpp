#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main(){ _ 
    int n; cin >> n;
    int seq = 0; int ans = 0;
    
    for(int i = 0; i < n; i++){
        char c; cin >> c;
        if(c == 'a') 
            seq++;
        if(c == 'b') {
            if(seq >= 2)
                ans += seq;
            seq = 0;
        }
    }
    if(seq >= 2)
        ans += seq;

    cout << ans << endl;
    return 0;
}