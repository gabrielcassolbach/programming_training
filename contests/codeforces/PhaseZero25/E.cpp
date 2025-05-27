#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define MAX 1123456789123

typedef long long ll; 

vector<int> primos, prime_factors, stop_cond; 
int y, k; 

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

ll compute(int i, int j, ll val, int it){
    if(it == 0) return val;
    if(j < stop_cond.size()){
        int aux = (stop_cond[j] - val) / prime_factors[i];
        return compute(i + 1, j + 1, stop_cond[j], it - aux);
    }
    if(val < prime_factors[i] && val < y){
        int aux = prime_factors[i] - val;
        return compute(i, j, val + aux, it - aux); 
    }
    if(val < y){
        int aux = (y - val)/prime_factors[i];
        return compute(i, j, y, it - aux); 
    }
    return compute(i, j, val + (it*y), 0); 
}

ll solve(){
    cin >> y >> k; 

    int i = 0; ll ans = 2; k--;  
    while(i < primos.size() && primos[i] <= y){
        if(y % primos[i] == 0) 
            prime_factors.pb(primos[i]);
        ++i;
    }  
    
    vector<int> stop_cond; 
    for(int i = 1; i < prime_factors.size(); i++)
        stop_cond.pb(prime_factors[i]*prime_factors[i-1]);

    i = 0; int j = 0; int it = k;    
    if(y == 1) return ans + (y*it);
    return compute(i, j, ans, it); 
}

int main() {
    fastio;    
    crivo();
    cout << solve() << '\n';
    return 0; 
}