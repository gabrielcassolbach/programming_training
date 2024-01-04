/* Coin Combinations I */
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 1123456
#define MEMO_SIZE 101

typedef long long ll;

const int mod = 1e9 + 7;

int v[MAX], n, x;
ll dp[MAX];

void initMemory(){
    for(int i = 0; i < MAX; i++)
        dp[i] = -1;
}

ll findSolutions(int value){
    ll a = 0;
    if(value == 0) return 1;
    for(int i = 1; i <= n; i++){ 
        if(value - v[i] < 0)
            a += 0;
        else if (dp[value - v[i]] != -1)
            a += dp[value - v[i]];
        else 
            a += (dp[value - v[i]] = findSolutions(value - v[i])); 
        a = a % mod;
    }
    return a;
}

void read(){
    cin >> n >> x;    
    for(int i = 1; i <= n; i++)
        cin >> v[i];
}

int main(){
    read();
    initMemory();
    printf("%lld\n", findSolutions(x));
    return 0;
}