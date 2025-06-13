#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

vector<ll> pot_dois;

ll bin_exp(ll n){
    if(pot_dois[n] != 0)
        return pot_dois[n];
    if(n % 2){
        pot_dois[n] = bin_exp(n-1) * 2;
    }
    else{
        pot_dois[n] = bin_exp(n/2)*bin_exp(n/2);
    }

    return pot_dois[n];
}

int main(){
    fastio; 
    pot_dois.resize(41);
    pot_dois[0] = 1;
    pot_dois[1] = 2;
    ll k, n; cin >> k >> n; 

    // Descobre se esta subindo ou descendo
    ll t_subida = bin_exp(k) * 3;
    ll t_descida = bin_exp(k-1) * 3;

    ll modulo_total = n%(t_subida + t_descida);

    int x_num, x_den;
    int y_num, y_den;

    if(modulo_total < t_subida){ // Subindo
        int mod_t = modulo_total % 3;
        y_num = modulo_total/3;
        if(mod_t == 1){
            y_num *= 2;
            y_num += 1;
            y_den = bin_exp(k+1);
        }
        else if(mod_t >= 2){
            y_num += 1;
            y_den = bin_exp(k);
        }
        
        x_num = modulo_total/3;
        x_den = bin_exp(k);
    }
    else{ // Descendo ou no topo
        modulo_total -= t_subida; // Novo modulo tirando o tempo de subida
        modulo_total *= 2; // Duplicar para lidar com 0,5 na descida

        int mod_t = modulo_total % 3;

        y_num = modulo_total/3;
        y_num = bin_exp(k) - y_num;

        x_num = modulo_total/3;
        y_den = bin_exp(k);
        if(mod_t == 2){
            x_num *= 2;
            x_num += 1;
            x_num = bin_exp(k+1) - x_num;
            x_den = bin_exp(k+1);
        }
        else{
            x_num = bin_exp(k+1) - x_num;
            x_den = bin_exp(k);
        }
    }

    if(x_num == x_den)
        cout << 1 << " ";
    else if(x_num == 0)
        cout << 0 << " ";
    else
        cout << x_num << "/" << x_den << " ";

    if(y_num == y_den)
        cout << 1 << "\n";
    else if(y_num == 0)
        cout << 0 << "\n";
    else
        cout << y_num << "/" << y_den << "\n";

    return 0;
}