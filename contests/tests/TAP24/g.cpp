#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s; 
    int p, t, a, u; 
    p = t = a = u = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'P') p++;
        if(s[i] == 'U') u++;
        if(s[i] == 'A') a++;
        if(s[i] == 'T') t++;
    }    
    int ans = min(p, t);
    cout << min(ans, u + a) << "\n";
    return 0;
}
