#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll n, a, b; cin >> n >> a >> b; 
    

    vector<int> v; 
    v.resize(n + 1, 0);
    
    v[0] = 0;
    for(int i = 1; i <= n; i++){
        int val; cin >> val;
        v[i] += v[i-1] + val;
    }

    ll b_pos; cin >> b_pos;
    ll ma_h = b + v[b_pos];

    for(int i = 1; i <= n; i++){
        if(a + v[i] >= ma_h && i != b_pos){
            cout << "SIM\n" << i << '\n';
            return 0;
        } 
    }

    cout << "NAO\n";
    return 0; 
}