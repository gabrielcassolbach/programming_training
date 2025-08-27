#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n; 

    int ans = 0;
    for(int i = 0; i < n; i++){
        
        int seq = 0;
        for(int j = 0; j < n; j++){
            char c; cin >> c; 
            if(c == 'B')
                seq = 0;
            if(c == 'N')
                seq++;

            if(seq == 2){
                ans++;
                seq = 0;
            }
        }
    }

    cout << ans << "\n";


    return 0;
}