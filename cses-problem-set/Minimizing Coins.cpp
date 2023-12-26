#include <bits/stdc++.h>
using namespace std;

#define MAXCOINS 100
#define MAX 1123456

int x, n, dp[MAX], coins[MAXCOINS];

void read(){
    scanf("%d %d", &n, &x);
    for(int i = 0; i < n; i++)
        scanf("%d", &coins[i]);
}

void init(){
    for(int i = 0; i < MAX; i++)
        dp[i] = x + 1; 
}

int getMaxCoins(){
    dp[0] = 0;
    for(int i = 1; i <= x; i++)
        for(int j = 0; j < n; j++)
            if(i - coins[j] >= 0)
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
    return dp[x] != x + 1 ? dp[x] : -1;  
}

int main(){
    read();
    init();
    printf("%d\n", getMaxCoins());
    return 0;
}

