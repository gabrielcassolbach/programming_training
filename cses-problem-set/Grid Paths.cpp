#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 1001

typedef long long ll;

const int mod = 1e9 + 7;

int n, m[MAX][MAX], dp[MAX][MAX];

void printMemory(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << dp[i][j] << "  ";
        }
        cout << endl;
    }
}

void init(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            dp[i][j] = 0;
}

void read(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char c; cin >> c;
            if(c == '.')
                m[i][j] = 1;
            else
                m[i][j] = 0;
        }
    }
}

ll moves(){
    dp[n][n] = m[n][n];

    if(!dp[n][n]) return 0;

    for(int i = n; i >= 1; i--){
        for(int j = n; j >= 1; j--){
            if(i == n && j == n) continue;
            
            if(m[i][j] == 0) continue;

            ll right = 0; ll down = 0;
            
            if(j + 1 <= n && dp[i][j+1])
                right = dp[i][j+1];

            if(i + 1 <= n && dp[i+1][j])
                down = dp[i+1][j];
            
            dp[i][j] = (right + down) % mod;
        }
    }
    return dp[1][1];
}

int main(){
    read();
    init();
    cout << moves() << endl;
    //printMemory();
    return 0;
}