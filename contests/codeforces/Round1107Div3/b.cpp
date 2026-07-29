#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int count_digits(ll x){
    int c = 0;
    while(x){
        c++;
        x /= 10;
    }
    return c;
}

ll exp10(int x){
    ll a = 1;
    for(int i = 0; i < x; i++)
        a *= 10;    
    return a;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t; 
    while(t--){
        ll x; cin >> x; 
        cout << exp10(count_digits(x)) + 1 << "\n";
    }
    return 0;
}