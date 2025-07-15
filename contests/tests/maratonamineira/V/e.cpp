#include <bits/stdc++.h>
using namespace std;

set<string> s; 
map<string, string> m; 
map<string, int> q; 

int main(){
    int n; cin >> n;
    string a, b;  
    for(int i = 0; i < n; i++){
        cin >> a >> b; 
        s.insert(a); s.insert(b);
        m[b] = a;
        if(q.find(b) == q.end())
            q[b] = 1;
        else 
            q[b]++;
        
        if(q.find(a) == q.end())
            q[a] = 1;
        else 
            q[a]++;
    }

    string first; 

    for(auto it = s.begin(); it != s.end(); it++){
        if(q[*it] == 1 && m.find(*it) != m.end())
            {first = *it;}
    }
    
    for(int i = 0; i < s.size(); i++){
        cout << first << '\n';
        first = m[first]; 
    }

    return 0; 
}
