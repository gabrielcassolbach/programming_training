#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 1123
#define MAX2 112345

int n, x; 
int price[MAX], pages[MAX], dp[MAX][MAX2];

int maxPages(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= x; j++)
            if(price[i] > j)
                dp[i][j] = dp[i - 1][j];
            else 
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-price[i]] + pages[i]); 
        
    return dp[n][x];
}

void init(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= x; j++)
            dp[i][j] = -1;

    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for(int i = 0; i <= x; i++)
        dp[0][i] = 0;
}

void read(){
    cin >> n >> x;
    for(int i = 1; i <= n; i++)
        cin >> price[i];
    for(int i = 1; i <= n; i++)
        cin >> pages[i];
}

int main(){
    read();
    init();
    cout << maxPages() << endl;
    return 0;
}