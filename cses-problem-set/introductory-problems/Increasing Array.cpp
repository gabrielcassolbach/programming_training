#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n, moves, value1, value2; 
    moves = 0;
    scanf("%lld", &n);
    scanf("%lld", &value1); 
    for(int i = 1; i < n; i++){
        scanf("%lld", &value2);
        //printf("(%lld %lld)\n", value1, value2);
        if(value2 < value1)
            {moves += (value1 - value2); value2 += (value1 - value2);}
        value1 = value2;
        //printf("moves: %lld\n", moves);
    }
    printf("%lld\n", moves);
    return 0;
}