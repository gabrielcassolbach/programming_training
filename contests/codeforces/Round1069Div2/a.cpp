#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define MAX 1123

int main(){
    fastio; 
    int t, n; cin >> t; 
   
    while(t--){
        cin >> n;
        int diff = 0; 
        vector<int> v; v.resize(MAX, 0);
        set<int> s;

        for(int i = 0; i < n; i++){
            int a; cin >> a; 
            if(!v[a]) {diff++; s.insert(a);}
            v[a]++;
        }

        if(v[diff]) cout << diff << "\n";
        else{
            diff++;
            while(!v[diff]) diff++;
            cout << diff << "\n";
        }             
    }

    return 0; 
}