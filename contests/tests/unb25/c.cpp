#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k, vol;
vector<ll> v;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> k >> vol; 
    v.resize(n+1);

    for(int i = 1; i <= n; i++) cin >> v[i];
    v[0] = -(1 << 30);
    sort(v.begin(), v.end());

    cout << min(v[n-k+1], vol/k) << "\n";


    return 0;
}