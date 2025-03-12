#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;

ll solve(ll a, ll b){
    if(b == 0) return a;
    if(b >= a - 1) return 1;
    return a;
}

int main(){
    int t; cin >> t;
    while(t--){
        ll a, b; cin >> a >> b;
        cout << solve(a, b) << endl;
    }
    return 0;
}