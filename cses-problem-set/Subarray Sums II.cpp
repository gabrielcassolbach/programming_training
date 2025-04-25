#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); 

struct event {
  int val;
  int idx; 
};

int n, x; 
vector<int> v;
vector<event> a; 

bool comp(event a1, event a2) {
  return a1.val < a2.val; 
}

ll getSubarr(ll val) {
  
  int a = 0, b = n-1;
  ll ans = 0;

  while((b-a) > 1) {
    

  }
 
}

void solve(){
  ll ans = 0; 
  vector<int> p_sum; p_sum.resize(n);  
  p_sum[0] = v[0];
  for(int i = 1; i < n; i++)
    p_sum[i] += p_sum[i-1] + v[i];

  sort(a.begin(), a.end(), comp);
  for(int i = 0; i < n; i++) 
    ans += getSubarr(v[i] + x);
  return ans; 
}

int main(){
    fastio;
    cin >> n >> x;
    v.resize(n); a.resize(n);
    for(int i = 0; i < n; i++){
      int value; cin >> value; 
      v[i] = value; 
      a[i] = {value, i};
    }   
    cout << solve() << '\n';
    return 0;
}


