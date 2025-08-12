#include <bits/stdc++.h>
using namespace std;

#define MAX 1123456

typedef long long ll;

int dig(int val){
    int sum = 0;
    while(val){
        sum += val%10;
        val/=10;
    }
    return sum;
}

int main(){ 
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, k; cin >> n >> k;

    vector<ll> f(MAX + 1, 0);
    int val;  
    for(int i = 0; i < n; i++)
        cin >> val, f[val]++;

    for(int i = MAX; i >= 0; i--){
        if(f[i] == 0) continue;
        if(f[i] < k){
            k -= f[i];
            f[i - dig(i)] += f[i];
        }else{
            cout << dig(i) << "\n";
            return 0;
        }
    }    

    cout << 0 << "\n";
    return 0;
}