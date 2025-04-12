#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

int n, k; 
vector<ll> v; 

bool test(ll c) {
    ll tmp = 0; ll ki = 0; 
    for(int i = 0; i < n; i++){
        if(v[i] > c) return false;
        if(v[i] + tmp <= c){
            tmp += v[i];
        }else{
            ki++;
            tmp = v[i];  
        }
    }
    ki++; 
    return (ki <= k); 
}

ll b_search(ll sum) {
    ll a = 0, b = sum;
    ll ans = sum; 
    while(a <= b) {
        ll c = (a + b)/2;
        if(test(c)){
            ans = c;
            b = c-1; 
        }else{
            a = c+1; 
        }
    }
    return ans;
}

int main(){
    fastio; 
    cin >> n >> k;
    v.resize(n); 
    ll sum = 0; 
    for(int i = 0; i < n; i++){
        cin >> v[i]; sum += v[i]; 
    }
    cout << b_search(sum) << '\n';
    return 0;    
}