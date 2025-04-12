#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long ll; 

string a, b; 
ll dp[19][2][2][2][10];

void read() {
  string ax = "", bx = "";
  cin >> ax >> bx;  
  string a_tmp(bx.size() - ax.size(), '0');
  a = a_tmp + ax; b = bx; 
}

ll count(int it, bool f_inf, bool f_sup, bool is_pad, int prev_d) {
  if(it == a.size()) return 1;
  ll &ans = dp[it][f_inf][f_sup][is_pad][prev_d];
  if(ans != -1) return ans;
  ans = 0;
  for(int i = 0; i <= 9; i++) {
    if(f_inf && a[it] - '0' > i) continue;
    if(f_sup && b[it] - '0' < i) continue;  
    if(i == prev_d && !is_pad) continue; 
    ans += count(it + 1, f_inf && a[it] - '0' == i,
                 f_sup && b[it] - '0' == i, is_pad && i == 0, i);
  }
  return ans; 
}

int main() {
  fastio; 
  read();
  memset(dp, -1, sizeof dp);
  cout << count(0, 1, 1, 1,-1) << '\n';
  return 0;
}
