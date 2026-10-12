#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define MAX 212345
#define MAX2 31

int n, q; 
vector<vector<int>> adj; 
int jump[MAX][MAX2];

int best_pow(int x){
    int i = 0; 
    while((1 << i) <= x) i++;
    --i;
    return i; 
}

void set_memo(){
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX2; j++)
            jump[i][j] = -1;
}

int solve(int x, int k){ 
    if((1 << k) == 1)  jump[x][k] = adj[x][0];
    if(jump[x][k] == -1) jump[x][k] = solve(solve(x, k-1), k-1);
    
    return jump[x][k];
}   

int main() {
    fastio; set_memo(); 
    cin >> n >> q; adj.resize(n+1);
    
    for(int i = 1; i <= n; i++){
        int val; cin >> val;
        adj[i].push_back(val);
    }
    
    for(int i = 1; i <= n; i++) solve(i, 30);        

    while(q--){
        int x, k; 
        cin >> x >> k;
        while(k > 0){
            int bp = best_pow(k);
            x = jump[x][bp];
            k -= (1 << bp);
        }        
        cout << x << "\n";
    }
    
    return 0;
}

