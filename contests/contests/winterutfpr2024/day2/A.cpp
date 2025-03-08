#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;

#define MAX 1000001

ll v[MAX];

ll dig(ll val){
    if(val < 10) return val;
    return (dig(val / 10) + val % 10);
}

int main(){
    _
    ll n, k;
    cin >> n >> k;
    for(int i = 0; i < MAX; i++) v[i] = 0;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        v[x]++;
    }
    for(int i = MAX; i > 0; i--){
        if(v[i] != 0){
            if(v[i] < k){
                k = k - v[i];
                v[i - dig(i)] += v[i];
            }else{
                cout << dig(i) << endl;
                return 0;
            }
        }
    }
    cout << 0 << endl;
    return 0;
}
