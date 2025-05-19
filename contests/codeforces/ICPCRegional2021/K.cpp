#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back

map<char, int> f_letter; 
vector<string> v;
int n; 

string solve() {
    for(int i = 0; i < n; i++){
        int possible = 1; 
        for(int j = 0; j < v[i].size() && possible; j++){
            if (f_letter[v[i][j]] == 0) possible = 0;
        }     
        if(possible) return "Y\n";  
    }
    return "N\n";
}

int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s; cin >> s; 
        v.pb(s);
        f_letter[s[0]]++;
    }
    cout << solve();
    return 0;
}