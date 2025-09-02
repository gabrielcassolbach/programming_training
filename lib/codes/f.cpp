#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int mod = 1e9 + 7;
int n; 
vector<vector<ll>> dp;
vector<vector<char>> grid; 
 
vector<int> dx = {-1, 0}, dy = {0, -1};
 
bool out_grid(int i, int j){
    return (i < 0 || j < 0 || i >= n || j >= n) || grid[i][j] == '*'; 
}
 
ll rec(int x, int y){
    if(out_grid(x, y)) return 0;
    if(x == 0 && y == 0) return 1; 
    if(dp[x][y] != -1) return dp[x][y]; 
 
    ll ans = 0;
    for(int i = 0; i < 2; i++)
        ans = (ans + rec(x + dx[i], y + dy[i])%mod)%mod;
 
    return dp[x][y] = ans%mod;
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n; 
    
    dp.resize(n, vector<ll> (n, -1));
    grid.resize(n, vector<char> (n));
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];
            
    cout << rec(n-1, n-1) << "\n";
 
    return 0; 
}