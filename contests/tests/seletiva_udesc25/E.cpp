#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll x, y; cin >> x >> y; 
    ll a = (x + y)/2;
    ll b = x - a;
    cout << a << " " << b << '\n';
    return 0; 
}