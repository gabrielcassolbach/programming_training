#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    scanf("%lld", &n);
    while(n != 1){
        printf("%lld ", n);
        if(n % 2 == 1) 
            n = (n*3) + 1;
        else
            n /= 2;
    }   
    printf("%lld \n", n);
    return 0;
}