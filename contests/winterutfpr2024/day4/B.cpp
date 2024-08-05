#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;

vector<ll> v;
ll n;

void read(){
    cin >> n;
    v.resize(n + 10);
    for(int i = 0; i < n; i++)
        cin >> v[i];
}

void solve(){
    ll ans = 0; ll sum = 0;
    queue<ll> q; 
    q.push(v[0]); sum += v[0];
    for(int i = 1; i < n; i++){
        if(sum % n == 0) ans++;
        else{
            

        }
    }
}

int main(){
    read();
    solve();
    return 0;
}