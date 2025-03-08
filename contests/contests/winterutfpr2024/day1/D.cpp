#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> v;
ll n;

void read(){
    cin >> n; v.resize(n + 10);
    for(int i = 1; i <= n; i++)
        cin >> v[i];
}

void solve(){
    ll ans = 0, A = 0;
    for(int i = 2; i <= n; i++){
        if(v[i] < v[i-1]){
            ans = abs(v[i] - v[i-1]);
            v[i] += ans;
            A += ans;
        }
    }
    cout << A << endl;
}

int main(){
    read();
    solve();
    return 0;
}