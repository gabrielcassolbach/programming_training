#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 102

string s; int n;

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n; cin >> s; 
    
        int i = 0, c = 0;
        while(s[i] == '?')
            {c++; i++;}
        
        if(c == n) {
            s[0] = 'R';
        }
        
        if(s[i] == 'R'){
            if(c % 2) {
                s[0] = 'B';
            } else {
                s[0] = 'R';
            }
        }
        else if(s[i] == 'B'){
            if(c % 2) {
                s[0] = 'R';
            } else {
                s[0] = 'B';
            }
        }
        /*B?*/
        for(int i = 1; i < n; i++) {
            if(s[i] != '?') continue;
            (s[i-1] == 'R') ? s[i] = 'B' : s[i] = 'R';
        }
        
        cout << s << endl;
    }
    return 0;
}