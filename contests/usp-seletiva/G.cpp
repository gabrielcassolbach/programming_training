#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 1123
#define INF 1e9

typedef long long ll;

ll n;
ll v[MAX];
ll dp[MAX][MAX];

void read(){
    cin >> n; v[0] = 0;
    for(int i = 1; i < n; i++){
        cin >> v[i];
    }
}

void setDp(){
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            dp[i][j] = INF;
    dp[0][0] = 0;
}

ll solve(){
    for(int i = 0; i < n; i++){ // posição da pessoa.
        for(int j = 0; j < n; j++){ // posição do portal.
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + abs(v[i+1] - v[i]));
            dp[i+1][i] = min(dp[i+1][i], dp[i][j] + abs(v[i+1] - v[j]));
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return -1;
}

int main() { _
    read();
    setDp();
    cout << solve() << endl;
    return 0;
}