#include <bits/stdc++.h>
using namespace std;
 
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX1 1000001
#define MAX2 101

typedef long long ll;

const int mod = 1e9 + 7;
 
ll n;
int x, dp[MAX1][MAX2];
vector<int> v;

int answer(int value, int k){
    ll ans = 0;
    cout << value << k << endl;
    if(value == 0) return 1; 
    if(dp[value][k] != -1) return dp[value][k]; 

    for(int i = k; i <= n; i++)
        if(value - v[i] >= 0)       
            ans += answer(value - v[i], i);
    
    dp[value][k] = ans % mod;
    return dp[value][k];
}

 
void read(){
    cin >> n >> x;
    v.resize(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    sort(v.begin() + 1, v.end(), greater<int>()); 
}

void init(){
    for(int i = 1; i <= x; i++)
        for(int j = 1; j <= n; j++)
            dp[i][j] = -1;
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
