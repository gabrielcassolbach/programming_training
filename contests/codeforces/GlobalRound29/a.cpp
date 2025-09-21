#include <bits/stdc++.h>
using namespace std;

int solve(int x, int y){
    if(x == y) return -1;
    if(x > y && y == 1) return -1;
    if(x > y && y > 1 && abs(x - y) == 1)  return -1;
    if(x > y && y > 1) return 3;
    return 2;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t; 
    while(t--){
        int x, y; cin >> x >> y;
        cout << solve(x, y) << "\n";
    }   
    return 0;
}