#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define f first
#define s second 

typedef long long ll;

int main() {
  fastio; 
  ll n; cin >> n; 
  vector<pair<ll, ll>> v;
  for(int i = 0; i < n; i++) {
    ll a, d; cin >> a >> d;
    v.push_back({a, d});
  }

  sort(v.begin(), v.end());

  ll counter = 0; ll ans = 0;
  for(int i = 0; i < n; ++i) {
    counter += v[i].f;
    ans += v[i].s - counter; 
  }   

  cout << ans << '\n';
  return 0; 
}
