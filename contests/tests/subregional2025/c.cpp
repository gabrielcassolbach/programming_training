#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll number, int n){
    if(number == 1) return 0; 
    if(number % 2 == 0) number = number >> 1; 
    else number = (number << 1) ^ number ^ 1;
    return solve(number, n) + 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    ll number = 0;
    for(int i = n; i >= 0; i--){
        int bit; cin >> bit;
        if(bit)
            number += (1 << i);
    }
    cout << solve(number, n) << "\n";
    return 0;
}