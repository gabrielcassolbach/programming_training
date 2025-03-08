#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;

vector<ll> v;

int main(){
    ll n; ll k; cin >> n >> k; v.resize(n*k*2);
    for(int i = 0; i < n*k*2; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    //for(int i = 0; i < v.size(); i++){
    //    cout << v[i] << endl;
    //}
    if(v.size())
        cout << abs(v[1] - v[0]) << endl;
    else 
        cout << 0 << endl;
    return 0;
}