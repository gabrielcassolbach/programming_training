#include <bits/stdc++.h>
using namespace std;

#define MAX_COINS 100
#define MAX 1123456

int n, x, coins[MAX_COINS], dp[MAX];

/*
3 9
2 3 5

dp[0] = 0;
dp[1] = 0;
dp[2] = 
*/

void init(){
    for(int i = 0; i < x; i++)
        dp[i] = 0;
}

int getAllCoinCombinations(){
    int comb = 0;
    dp[0] = 0;
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(i-coins[j] >= 0){
                //dp[i] += !(i % (i-coins[j]));
                printf("->%f<-\n", (float)!(i % (i-coins[j])));
                //if(dp[i-coins[j]])
                //    dp[i] += dp[i-coins[j]];
            }
        }
        //printf("dp[%d]: %d\n", i, dp[i]);
    }
    return comb;
}

void read(){
    scanf("%d %d", &n, &x);
    for(int i = 0; i < n; i++)
        scanf("%d", &coins[i]);
}

int main(){
    read();
    init();
    printf("%d\n", getAllCoinCombinations());
    return 0;
}