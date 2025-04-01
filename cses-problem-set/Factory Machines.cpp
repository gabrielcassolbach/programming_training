#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back

typedef long long ll; 

const ll INF = 1e18; 

ll n, t; 
vector<ll> v;

ll solve() {
  sort(v.begin(), v.end());
  ll a = 1; ll b = v[0]*t;
  ll t_ = INF;

  if(n == 1) return b;
  if(t == 1) return v[0];

  while((b-a) > 1) {
    ll ans = 0;
    ll option = (a+b)/2;
 
    for(int i = 0; i < n; i++){ 
      ans += option/v[i];
    }
 

    if(ans < t) {
      a = option;
    }else{
      b = option;
      t_ = min(option, t_); 
    }
  } 

  return t_; 
}

int main() {
  fastio;
  cin >> n >> t; 
  v.resize(n);
  for(int i = 0; i < n; i++)  
      cin >> v[i]; 
  cout << solve() << '\n';
  return 0;
}




