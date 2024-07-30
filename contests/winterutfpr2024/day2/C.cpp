#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> v;
set<int> aux;

int main(){
    int t; cin >> t;
    while(t--){
        int ans = 1;
        int n, x; cin >> n >> x; 
        v.resize(n + 10);
        for(int i = 0; i < n; i++) cin >> v[i];
        for(int i = 0; i < n; i++){
            if(!aux.size()) aux.insert(x);
            for(auto it = aux.begin(); it != aux.end(); it++){
                //cout << *it << " ";
                if(*it % v[i] == 0) {
                    aux.insert(*it / v[i]);    
                }
            }
            //cout << endl;
            if(*aux.begin() == 1){
                //cout << "a" << endl;
                ans++;
                aux.clear();
                aux.insert(x);
                if(x % v[i] == 0) {
                    aux.insert(x / v[i]);    
                }
            }
        }
        v.clear();
        aux.clear();
        cout << ans << endl; 
    }
    return 0;
}