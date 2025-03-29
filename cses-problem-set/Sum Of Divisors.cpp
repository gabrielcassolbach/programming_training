#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define MAX 1123456
#define fst first
#define scd second

typedef long long ll; 

const ll mod = 1e9 + 7; 

ll first_part (ll n, ll a) {
  ll sum = 0;
  for(ll i = 1; i < a && i <= n; i++)
     {sum += (i%mod)*((n/i)%mod); sum %= mod;} 
  return sum; 
}

ll exp_bin(ll a, ll b) {
  if(b == 0) return 1;
  if(b % 2) return (exp_bin(a, b-1)*a)%mod;
  ll val = exp_bin(a, b/2);
  return (val*val)%mod; 
}

pair<ll, ll> second_part (ll n) {
  ll sum = 0; ll l_a = 1e12l + 10; 
  for(ll k = 1; (k*k) < n; k++) {

    ll a = n % (k+1) == 0 ? n/(k+1) + 1 : ceil((long double)n/(k +1)); 
    ll b = n/k;
    l_a = min(l_a, a);  
 
    sum += (k*(((((b-a+1)%mod)*((a%mod)+(b%mod)%mod))%mod)*(exp_bin(2, mod-2))%mod)%mod);  
    
    sum = sum % mod;  
 
  }
  return {sum, l_a};  
}

ll solve (ll n) {
  auto [sum, a] = second_part(n);
  return (sum + first_part(n, a))%mod; 
}

int main() {
  fastio;
  ll n; cin >> n; 
  cout << solve(n) << '\n';
  return 0; 
}


