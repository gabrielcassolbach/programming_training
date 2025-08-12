#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
    int n; cin >> n; 
    string s, t; 
    cin >> s >> t; 
    cout << std::fixed << std::setprecision(2);
    double ns = 0.00, nt = 0.00; 
    for(int i = 0; i < n; i++){
        if(s[i] == '*') ns+=1.00;
        if(t[i] == '*') nt+=1.00;
    }
    cout << ((double)1 ) -nt/ns << '\n';
    return 0;
}