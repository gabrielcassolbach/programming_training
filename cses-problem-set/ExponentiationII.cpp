#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll; 

const ll mod = 1e9 + 7; 

ll exp(ll a, ll b, ll m) {
  if(b == 0) return 1;
  if(b % 2)
    return (exp(a, b-1, m)*a)%m; 
  ll val = exp(a, b/2, m);  
  return (val*val)%m;
}

ll solve() {
  ll a, b, c; cin >> a >> b >> c; 
  return exp(a, exp(b, c, mod-1), mod);   
}

int main() {
  fastio; 
  int n; cin >> n;
  while(n--) cout << solve() << '\n';
  return 0; 
}
