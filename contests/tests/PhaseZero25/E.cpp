#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define MAX 112345

typedef long long ll; 

vector<ll> primos, prime_factors, jumps;
vector<ll> d;
ll y, k; 

void crivo(){
    vector<ll> primos_ax; 
    primos_ax.resize((ll) MAX, 1);
    for(ll i = 2; i < (ll) MAX; i++){
        if(!primos_ax[i]) continue;
        for(ll j = i+i; j < (ll) MAX; j+=i)
            primos_ax[j] = 0; 
    }
    for(ll i = 2; i < (ll) MAX; i++)   
        if(primos_ax[i])
            primos.pb(i);
}


ll get_jumps(ll it, ll k){
    if(it == prime_factors.size() || k < (prime_factors[it] - 1))
        return (ll)(k+1)*jumps[it];
    return get_jumps(it + 1, k - (prime_factors[it] - 1));
}

void get_factors(ll n){
    for(int i = 0; i < (ll) primos.size() && n > 1 && primos[i] <= n; i++)
        while(!(n % primos[i])) prime_factors.pb(primos[i]), n /= primos[i];
    if(n != 1) prime_factors.pb(n);
}

ll solve(){
    cin >> y >> k;
  
    get_factors(y);
    
    jumps.resize(prime_factors.size() + 1, 1);
    for(int i = 0; i < prime_factors.size(); i++)
        jumps[i+1] = prime_factors[i]*jumps[i];

    return get_jumps(0, k);
}

int main() {
    fastio;    
    crivo();
    cout << solve() << '\n';
    return 0; 
}