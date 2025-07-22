#include <bits/stdc++.h>
using namespace std;

int n; string s;
vector<int> alfabet;

bool isChar(char c) {return c >= 'a' && c <= 'z';}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n; cin >> s;
    alfabet.resize(26, 0);

    
    int i = 0, j = 1; int sum = 1, ans = 0;
    for(; i < (int) s.size(); i++){
        if(!isChar(s[i])) continue;
        alfabet[s[i] - 'a'] = 1;

        if(i >= j) {j = i + 1; sum = 1;}

        while(j < (int)s.size() && isChar(s[j]) && !alfabet[s[j] - 'a']){
            alfabet[s[j] - 'a'] = 1;
            j++; sum++;
        }

        ans = max(ans, sum);
        alfabet[s[i] - 'a'] = 0;
        sum--;
    }
   
    cout << ans << '\n';
    
    return 0;
}
