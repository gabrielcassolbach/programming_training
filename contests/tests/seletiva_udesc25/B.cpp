#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    vector<char> s;
    vector<char> ordered_s;
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        char c; cin >> c;
        s.push_back(c);
        ordered_s.push_back(c);
    }
    
    //copy(s.begin(), s.end(), ordered_s.begin());
    sort(ordered_s.begin(), ordered_s.end());
    
    // for(auto c: ordered_s){
    //     cout << c << "";
    // }
    // cout << "\n";

    for(int i = 0; i < s.size(); i++){
        if(s[i] != ordered_s[i]){
            auto swap_p = find(s.rbegin(), s.rend(), ordered_s[i]);
            swap(s[i], *swap_p);

            break;
        }
    }

    for(auto c: s){
        cout << c << "";
    }
    cout << "\n";

    return 0; 
}