#include <bits/stdc++.h>
using namespace std;
 
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX1 1000001
#define MAX2 101

const int mod = 1e9 + 7;
 
int n, x;
int dp[MAX1][MAX2];
vector<int> v;
 
int answer(int value, int k){
    int ans = 0;
    if(value == 0) 
        return 1; 
    for(int i = k; i <= n; i++)
        if(value - v[i] >= 0)
            ans += answer(value - v[i], i);
    return ans;
}
 
void init(){
    for(int i = 1; i < MAX1; i++)
        for(int j = 1; j < MAX2; j++)
            dp[i][j] = -1;
}
 
void read(){
    cin >> n >> x;
    v.resize(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> v[i]; 
}
 
int main(){
    read();
    init();
    if(n == 1 && v[1] <= x)
        cout << 1 << endl;
    else
        cout << answer(x, 1) << endl;
    return 0;
}