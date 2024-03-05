#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAX 112345
#define MAX2 103

const int mod = 1e9 + 7;
ll dp[MAX][MAX2]; vector<int> v; int n, m;

void read(){
    cin >> n >> m;
    v.resize(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> v[i];
}

void init(){
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX2; j++)
            dp[i][j] = 0;

    if(v[1])
        {dp[1][v[1]] = 1;}
    else{
        for(int i = 1; i <= m; i++)
            dp[1][i] = 1;
    }
}

int main(){
    read();
    init();
    for(int i = 2; i <= n; i++){
        if(v[i])
            {dp[i][v[i]] = (dp[i-1][v[i]] + dp[i-1][v[i]-1] + dp[i-1][v[i]+1]) % mod;}
        else{
            for(int j = 1; j <= m; j++)
                {dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % mod;}
        }
    }

    ll ans = 0;
    for(int i = 1; i <= m; i++)
        ans += (dp[n][i]) % mod;

    cout << ans % mod << endl;
    return 0;
}



/*
n -> [1, 10^5]
m -> [1, 100].
*/
