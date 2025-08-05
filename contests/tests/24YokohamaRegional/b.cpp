#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll countone(ll n){
    ll cont = 0; 
    while(n){
        cont += n%(2ll);
        n /= (2ll);
    }
    return cont; 
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    ll a, b; cin >> a >> b;

    if(a == b){
        cout << a << "\n";
        return 0;
    }

    for(int i = 0; i <= 60; i++){
        ll val = 1ll << i;      
        if(val >= a && val <= b){
            cout << val << "\n";
            return 0;
        }
        if(val > b) break;
    }
    // pegar o prefixo comum.
    // 
    if(countone(a) <= countone(a+1)){
        cout << a << "\n";
    }else{
        cout << a + 1 << "\n";
    }

    return 0;
}

/*

101001 até <1000000

1000000

110000

101010


*/