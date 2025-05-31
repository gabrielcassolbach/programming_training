#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll; 

vector<int> v;
ll dp[4][1000][8001];

ll knapsack(int qt_sub, int it, int w){
    if(qt_sub == 0) return w == 0;
    if(it < 0) return 0;
    if(w < -4000 || w > 4000) return 0;
    if(dp[qt_sub-1][it][w + 4000] != -1) 
        return dp[qt_sub-1][it][w + 4000];
    return dp[qt_sub-1][it][w + 4000] = 
        knapsack(qt_sub, it-1, w) + knapsack(qt_sub-1, it-1, w-v[it]);
}

int main(){
    fastio;
    int n, q; 
    cin >> n; v.resize(n); 
    for(int i = 0; i < n; i++)
        cin >> v[i];
    memset(dp, -1, sizeof dp);
    cin >> q;
    while(q--){
        int val; cin >> val;
        cout << knapsack(4, n-1, val) << '\n';
    }
    return 0;
}