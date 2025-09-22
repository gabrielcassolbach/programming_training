#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<char> s(n); 
    
    for(int i = 0; i < n; i++)
        cin >> s[i];
    
    int open = 0, ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '(') open++;
        if(s[i] == ')' && open != 0)  
            {open--;}
        else if(s[i] == ')' && open == 0)  
            {ans = i + 1;}
    }

    cout << ans << "\n";

    return 0;
}