#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

#define MAX 1000001

ll v[MAX];

ll dig(ll val){
    ll ans = 0;
    while(val > 0){
        int d = val%10;
        ans += d;
        val /= 10;
    }
    return ans;
}

int main(){
    ll n, k;
    cin >> n >> k;
    for(int i = 0; i < MAX; i++) v[i] = 0;
    ll g = -1;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        v[x]++;
        g = max(g, x);
    }
    for(int i = MAX; i > 0; i--){
        if(v[i] != 0){
            ll sum_dig = dig(i);
            if(v[i] < k){
                k = k - v[i];
                v[i - sum_dig] += v[i];
            }else{
                cout << sum_dig << endl;
                return 0;
            }
        }
    }
    cout << 0 << endl;
    return 0;
}