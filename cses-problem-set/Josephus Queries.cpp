#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll; 

int j0_(int n, int k);
int j1_(int n, int k);

int j0_(int n, int k){
    if(n == 1) return 1; 
    if(k <= n/2) return 2*k; 
    if(k > n/2)
        return (n % 2) ?  2*j1_(n - n/2, k-n/2) - 1 :
                          2*j0_(n - n/2, k-n/2) - 1;
}

int j1_(int n, int k){
    if(k <= ceil(n/2.0)) return (2*k - 1);
    if(k > ceil(n/2.0))
        return (n % 2) ?  2*j0_(n-ceil(n/2.0), k-ceil(n/2.0)) :
                          2*j1_(n-ceil(n/2.0), k-ceil(n/2.0));
}

int main() {
    fastio; 
    int q; cin >> q; 
    int n, k;; 
    while(q--){
        cin >> n >> k;
        cout << j0_(n, k) << '\n';
    }
    return 0; 
}