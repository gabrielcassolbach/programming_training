#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

string solve(int x, int y){
    if(abs(x) > 200 || abs(y) > 100) return "N";
    
    if(x >= -100 && x <= 0){
        if(y >= 0 && y <= 100) return "S";
        if(y < 0 && -x - y <= 100) return "S";
    }

    if(x >= 0 && x <= 100){
        if(y <= 0 && y >= -100) return "S";
        if(y > 0 && (x + y) <= 100) return "S";
    }

    if(x < -100 && x >= -200)
        if(y >= 0 && (-x + y) <= 200) 
            return "S";

    if(x > 100 && x <= 200)
        if(y <= 0 && (x - y) <= 200) 
            return "S";

    return "N";
}

int main(){
    fastio;
    int n; cin >> n; 
    while(n--){
       int x, y; cin >> x >> y; 
       cout << solve(x, y) << '\n'; 
    }
    return 0;
}