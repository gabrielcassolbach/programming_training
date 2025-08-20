#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

int n, c, t;
vector<ll> v;

bool test_limit(ll lim){
    ll seq = 0;
    int q_comp = c; 
    for(int i = 0; i < n; i++){
        if(v[i] + seq > lim && q_comp == 1)
            return false; 

        if(v[i] + seq <= lim)
            {seq += v[i];}
        else{
            if(v[i] > lim) return false;
            seq = v[i]; 
            q_comp--;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> c >> t;  
    v.resize(n); 

    for(int i = 0; i < n; i++)
        cin >> v[i];

    
    ll a, b, ans; 
    a = 1; b = (1 << 30); ans = (1 << 30);
    
    while(a <= b){
        ll m = (a + b)/2;
        bool possible = test_limit(m*t);
        if(possible)
            {b = m-1; ans = min(ans, m);}
        else
            {a = m+1;} 
    }

    cout << ans << "\n";

    return 0; 
}