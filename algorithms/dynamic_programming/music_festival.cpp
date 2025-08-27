#include <bits/stdc++.h>
using namespace std;

struct event {
    int b, e, o; 
};

int n; 
vector<vector<event>> v; 

void rec(int set, int previous, int mask){     
    if(__builtin_popcount(set) == 1 ) {

        return;
    }

    for(int i = n-1; i >= 0; i--){
        if(i == previous) continue;
        rec(((~(1 << i)) & mask) & set, i, mask);  
    }
    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n; int mask = (1 << n) - 1;
    
    v.resize(n + 1);
    for(int i = 1; i <= n; i++){
        int m; cin >> m; 
        for(int j = 1; j <= m; j++){
            int a, b, c; cin >> a >> b >> c;  
            v[i].push_back({a, b, c});
        }
    }

    rec(mask, -1, mask);
    return 0;
}