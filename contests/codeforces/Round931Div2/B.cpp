#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 150

typedef long long ll;

int dp[MAX];

void dpTable(){
    int v[] = {1, 3, 6, 10, 15};
    dp[0] = 0;
    for(int i = 1; i <= MAX; i++){
        dp[i] = 12345678;
        for(int j = 0; j < 5; j++)
            if(v[j] <= i)
                {dp[i] = min(dp[i], dp[i - v[j]] + 1);}
    }
}

int main(){
    int t; cin >> t;
    dpTable();
    while(t--){
        int n; cin >> n;
        ll ans = 0;
        if(n > 140)
            ans += (n-100)/15 + (dp[(n-100)%15 + 100]);
        else
            ans += dp[n];
        cout << ans << endl;
    }
    return 0;
}

