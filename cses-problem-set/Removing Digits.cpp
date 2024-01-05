#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 1123456

int dp[MAX], n;

void initMemory(){
    dp[0] = 0;
    for(int i = 1; i <= n; i++)
        dp[i] = MAX;
}

int solve(){
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        int temp = i;
        while(temp != 0){
            int digit = temp % 10; temp /= 10; 
            dp[i] = min(dp[i - digit] + 1, dp[i]);
        }
    }
    return dp[n];
}

int main(){
    cin >> n;
    initMemory();
    cout << solve() << endl;
    return 0;
}