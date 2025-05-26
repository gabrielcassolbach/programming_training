#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll; 

int main() {
    fastio;
    ll m; cin >> m; 
    long double conv = 8; 
    cout << ceil(log2((long double) m*8*1000000)) << '\n';
    return 0;
}