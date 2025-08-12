#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back

typedef long long ll;

vector<ll> get_bits(ll x) {
    vector<ll> bits;
    while(x > 0){
        if(x % 2) 
            x -= 1, bits.pb(1ll);
        else
            bits.pb(0);
        x /= (ll)2;       
    }
    reverse(bits.begin(), bits.end());
    return bits;
}

pair<ll, ll> solve(ll x){
    vector<ll> bits = get_bits(x);
    ll ans = 0, half_ans = 0; 
    
    for(ll i = 0; i < bits.size()/2 + (bits.size() % 2); i++)
        ans += bits[i]*((ll)1 << (ll)(bits.size() - 1 - i));    
    
    half_ans = ans;
    for(ll i = 0; i < bits.size()/2; i++)
        ans += bits[bits.size()/2 - 1 - i]*((ll)1 << (ll)bits.size()/2 - 1 - i); 
    
    return {ans, half_ans};
}

int main() {
    fastio; 
    vector<ll> bits; 
    ll x; cin >> x; 

    ll ans, half_ans;
    auto value = solve(x);
   
    ans = value.first; half_ans = value.second;

    if(ans > x){
        bits.clear();
        ans = solve(half_ans-1).first;
    }
    
    cout << ans << '\n';
    return 0;
}