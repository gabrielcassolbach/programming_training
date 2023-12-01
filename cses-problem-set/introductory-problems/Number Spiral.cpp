#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll getDiagonal(ll n){
    return (1 + ((2 + (n-1)*2)*(n-1))/2); 
}

ll getPos(ll y, ll x){
    ll d, v;
    v = y > x ? y : x;
    d = getDiagonal(v); // tempo constante.
    if(y == x)
        return(d); // tempo constante.
    else if(y < x)
        return (v % 2 == 0) ? (d - (x - y)) : (d + (x - y)); // tempo constante.
    else
        return (v % 2 == 0) ? (d + (y - x)) : (d - (y - x)); // tempo constante.
}

int main(){
    ll t, y, x;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld %lld", &y, &x);
        printf("%lld\n", getPos(y, x));
    }
    return 0;
}