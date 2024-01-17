#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 212345

string s;
int t, a, b, qtd_a, qtd_b, n;
bool ans = 1; 

void read(){
    cin >> a >> b; 
    n = a + b;
    cin >> s;
    for(int i = 0; i < s.size()/2 + 1; i++){ 
        if(s[i] != '?' && s[n-1-i] == '?')
            s[n-1-i] = s[i];
        else if(s[i] == '?' && s[n-1-i] != '?')
            s[i] = s[n-1-i];
        else if(s[i] != '?' &&  s[n-1-i] != '?' && s[i] != s[n-1-i])
            ans = 0;
    }   
}

void printAns(){
    if(ans == 0) cout << -1 << endl;
    else cout << s << endl;  
}

int main(){
    cin >> t;
    while(t--){
        ans = 1;
        read();
        qtd_a = a - (count(s.begin(), s.end(),'0'));
        qtd_b = b - (count(s.begin(), s.end(),'1'));
        if (qtd_a < 0 || qtd_b < 0) 
            ans = 0;    
        for(int i = 0; i < s.size()/2 + 1; i++) {          
            if(s[i] == '?'){
                if(i == n-1-i && (qtd_a > 0 || qtd_b > 0)) {
                    if (qtd_a > 0){
                        s[i] = '0'; qtd_a--; 
                    } else {
                        s[i] = '1'; qtd_b--;
                    }
                }else if (qtd_a > 1 ) {
                    s[i] = '0';
                    s[s.size()-i-1] = '0';
                    qtd_a -= 2;
                }
                else if (qtd_b > 1 ) {
                    s[i] = '1';
                    s[s.size()-i-1] = '1';
                    qtd_b -= 2;
                }
                else {
                    ans = 0;
                }
            }
        }
        if(qtd_a != 0 || qtd_b != 0)
            ans = 0;
        printAns();
    }
    return 0;
}