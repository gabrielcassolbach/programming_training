#include <bits/stdc++.h>
using namespace std;

#define MAX 212345

typedef long long ll;

ll nums[MAX], lis[MAX];
ll n, ans; 

void read(){
    scanf("%lld", &n);
    for(int i = 0; i < n; i++)
        scanf("%lld", &nums[i]);
}

ll dp(){
    int value, best_value;
    ans = 1; lis[n-1] = 1; 
    for(int i = n-2; i >= 0; i--){
        best_value = 1;
        for(int j = (i+1); j <= n-1; j++){
            value = nums[i] < nums[j] ? 1 + lis[j] : 1;
            best_value = value > best_value ? best_value = value : best_value;
        }
        lis[i] = best_value;
        ans = ans < best_value ? best_value : ans;
    } 
    return ans;  
}

int main(){
    read();
    printf("%lld\n", dp());
    return 0;
}


