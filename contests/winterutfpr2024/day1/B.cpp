#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll t, s, q, x, M, m;

int main(){
    M = m = 0;
    cin >> t; 
    while(t--){
        vector<int> v;
        cin >> s >> q;
        while(q--){
            cin >> x; 
            
            m = max(m, min(x, s - x));
        }
        cout << m << " " << M << endl;
    }
    return 0;
}