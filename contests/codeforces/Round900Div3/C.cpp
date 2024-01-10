#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll t, n, k, x;

int main(){
    scanf("%lld", &t);
    while(t--){
        scanf("%lld %lld %lld", &n, &k, &x);
        ll sum1 = (((n-k + 1) + n)*k)/(ll)2;
        ll sum2 = ((1+k)*k)/(ll)2;
        if(x >= sum2 && x <= sum1) 
            printf("YES\n");
        else 
            printf("NO\n");
    }
    return 0;
}