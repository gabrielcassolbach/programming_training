#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

ll a, b, m;

int main(){
    int t; cin >> t;
    while(t--){
        cin >> a >> b >> m;
        cout << (m / a) + (m / b) + 2 << endl;
    }
    return 0;
}