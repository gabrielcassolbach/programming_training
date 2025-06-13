#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

int main(){
    fastio;
    int w, a, b, c; 
    cin >> w >> a >> b >> c; 
    if(w - (a + b + c) >= 0) cout << "S\n";
    else cout << "N\n";
    return 0;
}