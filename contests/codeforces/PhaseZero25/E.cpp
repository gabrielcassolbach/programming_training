#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define MAX 1123456789

typedef long long ll; 

vector<int> primos, prime_factors, stop_cond; 
vector<ll> d;
int y, k; 

// ok!
void crivo(){
    vector<int> primos_ax; 
    primos_ax.resize((int) sqrt(MAX), 1);
    for(int i = 2; i < (int) sqrt(MAX); i++){
        if(!primos_ax[i]) continue;
        for(int j = i+i; j < (int) sqrt(MAX); j+=i)
            primos_ax[j] = 0; 
    }
    for(int i = 2; i <= (int) sqrt(MAX); i++)   
        if(primos_ax[i])
            primos.pb(i);
}


ll solve(){
    cin >> y >> k; 
    int i = 0; ll ans = 2; k--;  
    if(k == 0) return ans; 

    
   


    return 1;
}

int main() {
    fastio;    
    crivo();
    cout << solve() << '\n';
    return 0; 
}