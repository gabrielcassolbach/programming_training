#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n; 
    int val; cin >> val;
    --n; 
    bool ans = true;
    while(n--){
        int others; cin >> others;
        if(others > val)
            ans = false; 
    }

    cout << (ans ? "S" : "N") << "\n";
    return 0; 
}