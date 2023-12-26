#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
const int mod = 1e9 + 7;

int dp[1123456];

void init(int n){
    for(int i = 1; i <= n; i++)
        dp[i] = -1;
}

int combinations(int n){
    int ans = 0;
    if(n < 0) 
        return 0;
    if(n == 0)
        return 1;
    if(dp[n] != -1)
        return dp[n];
    for(int i = 1; i <= 6; i++)
        {ans += combinations(n-i); ans %= mod;}
    return dp[n] = ans;
} 

int main(){
    int n; scanf("%d", &n);
    init(n);
    printf("%d\n", combinations(n));
    return 0;
}