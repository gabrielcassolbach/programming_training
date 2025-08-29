#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t; 
    while(t--){
        string s; cin >> s; 
        sort(s.begin(), s.end());
        int ans = 0, seq = 1;
        for(int i = 1; i < (int) s.size(); i++){
            if(s[i] == s[i-1]) seq++;
            else {
                ans += seq*(seq-1);
                seq = 1;
            }
        }
        ans += seq*(seq-1);
        cout << ans << "\n";
    }


    return 0;
}