#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; 
    
    vector<int> v, first_match; set<int> s;  
    
    cin >> n; v.resize(n); first_match.resize(101, 0);
    for(int i = 0; i < n; i++){
        cin >> v[i]; 
        if(s.find(v[i]) == s.end()){
            s.insert(v[i]);     
            first_match[v[i]] = i;
        }
    }

    int ans = 0;
    
    for(auto it = s.begin(); it != s.end(); it++){
        int i = first_match[*it];
        bool dont_add = false;

        for(; i < n; i++){
            if(v[i] < *it){
                ans++;
                while(i < n && v[i] != *it) i++;
                if(i == n && v[i] != *it) dont_add = true;
            }
        }
        
        if(!dont_add)
            ans++;
    }
    
    cout << ans << "\n";
    return 0;
}