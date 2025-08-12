#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);


int main() {
    fastio;
    int c, g; cin >> c >> g; 
    if(c == 0){
        if(g == 0) cout << "morto\n";
        else cout << "vivo\n";
    }else{
        cout << "vivo e morto\n";
    }
    return 0;
}