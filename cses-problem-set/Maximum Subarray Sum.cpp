/* Segmento de Soma Máxima. */
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

int main(){
    int n; cin >> n;
    vector<ll> memory; memory.resize(n);
    vector<ll> v; v.resize(n);
    
    for(int i = 0; i < n; i++) 
        {cin >> v[i];}

    memory[0] = v[0];
    for(int i = 1; i < n; i++){ 
        if(memory[i-1] >= 0)
            memory[i] = v[i] + memory[i-1];
        else
            memory[i] = v[i];
    }   

    ll ans = -INT_MAX;
    for(int i = 0; i < n; i++){
        if(memory[i] >= ans)
            ans = memory[i];
    }
    cout << ans << endl; 

    return 0;
}