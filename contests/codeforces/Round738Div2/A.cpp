#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 31

typedef long long ll;

int main(){
    int n, t; cin >> t;
    vector<ll> v;
    while(t--){
        ll ans;
        cin >> n; v.resize(n);
        cin >> v[0]; ans = v[0];
        for(int i = 1; i < n; i++){
            cin >> v[i];
            ans = ans & v[i];    
        } 
        cout << ans << endl;
        v.clear();
    }
    return 0;
}