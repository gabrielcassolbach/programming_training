#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

vector<int> v1, v2;

int set_cicle(vector<int> &cicles, int j, int val, int size){
    if(v1[j] == val) return size + 1;
    return cicles[j] = set_cicle(cicles, v1[j], val, ++size);
}

int main() {
    fastio; 
    int n; cin >> n;

    v1.resize(n + 1); 
    v2.resize(n + 1);

    for(int i = 1; i <= n; i++)
        cin >> v1[i];
    for(int i = 1; i <= n; i++)
        cin >> v2[i];

            

    vector<int> cicles; 
    cicles.resize(n + 1, 0);
    for(int i = 1; i <= n; i++){
        if(cicles[i] != 0) continue;
        int val = v1[i];
        int j = val;
        cicles[i] = set_cicle(cicles, j, val, 0);
    }

    vector<int> vis; vis.resize(n + 1, 0);
    int cycle_elem = 0;
    for(int i = 1; i <= n; i++){

        if(v2[i] == 0) {cycle_elem++; continue;}
        if(vis[i]) {continue;}
        
        if(cycle_elem + 1 <= cicles[v2[i]]){ 
            int val = v2[i];
            int search = true;
            int cycle_begin = i-cycle_elem;
            int cycle_it = 1;
            int j = cycle_elem + 1 < cicles[v2[i]] ?  i+1 : i-cycle_elem;
            
            while(search && j <= n){
                val = v1[val]; 
                search = val != v2[i] ? true : false;
                search = v2[j] != 0 && val != v2[j] ? false : search; 

                if(search)
                    {v2[j] = val; vis[j] = 1; cycle_it++;}

                j = j == n || (cycle_it + cycle_elem) == cicles[v2[i]] ? cycle_begin : j+1;
            }
            
            cycle_elem = 0;
        }else{  
            cout << -1 << '\n';
            return 0;
        }
    }

    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        if(v2[i] == 0) 
            {cout << -1 << '\n'; return 0;}
        ans.push_back(v2[i]);
    }

    for(int i = 0; i < n; i++) 
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}

/*
-> v2[j] == 0

*/