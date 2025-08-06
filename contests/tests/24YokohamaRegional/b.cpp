#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string countOne(ll n){
    string count = "";
    while(n) {
        count += (n%2) == 1 ? '1' : '0';
        n /= 2;
    }
    reverse(count.begin(), count.end());   
    return count;
}   

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    ll a, b; cin >> a >> b;
    vector<ll> pot2(61);
    if(a == b){
        cout << a << "\n";
        return 0;
    }
    ll val;
    for(int i = 0; i <= 60; i++){
        val = 1ll << i;      
        pot2[i] = val;
        if(val >= a && val <= b){
            cout << val << "\n";
            return 0;
        }
        if(val > b) {
            val = 1ll << (i-1);
            break;
        }
    }
    cout << "val: " << val << "\n";
    cout << countOne(a) << "\n";
    cout << countOne(b) << "\n";
    cout << countOne(val) << "\n";
    
    return 0;
}

