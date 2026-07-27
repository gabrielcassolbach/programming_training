#include <bits/stdc++.h>
using namespace std;

string solve(){
    int x, y; cin >> x >> y;
    if (y > x) return "NO"; 
    if ((x % y) == 0) return "YES";
    return "NO";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);  
    int t; cin >> t; 
    while(t--){
        cout << solve() << "\n";
    }
    return 0;
}