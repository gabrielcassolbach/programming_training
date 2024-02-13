#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

ll n, a, b;

int inSet(){
    if(a == 1){
        if(!((n - 1) % b)) return 1;
        return 0;
    }

    ll k = 1;
    while(k <= n){
        if(!((n - k) % b)) return 1;
        k = a * k;
    }
    return 0;
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> a >> b;
        if(inSet())
            cout << "Yes" << endl;
        else 
            cout << "No" << endl;
    }
    return 0;
}