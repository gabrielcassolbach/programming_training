#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    queue<int> q; string s;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        char c; cin >> c;
        s.push_back(c);
    }
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            q.push(i);
        }else if(s[i] == ')' && q.size() >= 1){
            for(int j = q.front(); j < i + 1; j++){
                s[j] = '.';
            }
            q.pop();
        }
    }
    for(int i = 0; i < n; i++){
        if(s[i] != '.'){
            cout << s[i];
        }
    }
    cout << endl;
    return 0;
}