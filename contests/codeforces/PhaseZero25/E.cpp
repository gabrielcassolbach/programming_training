#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define MAX 1123456789

typedef long long ll; 

vector<int> primos; 
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

void solve(){
    cin >> y >> k; 
    vector<int> prime_factors; 
    int i = 0; ll ans = 1; k--;  
    while(i < primos.size() && primos[i] <= y){
        if(y % primos[i] == 0) 
            prime_factors.pb(primos[i]);
        ++i;
    }  
    for(int = 0; i < prime_factors.size(); i++){



    }

}

int main() {
    fastio;    
    crivo();
    solve();
    return 0; 
}