#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string a, b; 
    cin >> a; cin >> b;
    
    int lim = (int) a.size() -  (int) b.size();
    int ans = 0;  

    for(int shift = 0; shift <= lim; shift++){
        bool ok = true;

        for(int j = 0; j < (int) b.size(); j++)
            if(a[shift + j] == b[j])
                ok = false;
        
        if(ok) 
            ans++;
    }

    cout << ans << "\n";
    
    return 0;
}