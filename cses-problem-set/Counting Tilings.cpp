#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define MAX 1123
#define MAX2 (1 << 10) + 10
#define bits(i) ((val & (1 << (i))) != 0) 

typedef long long ll; 

const int mod = 1e9 + 7; 
int n, m;
ll dp[MAX][MAX2];  


bool valid(int val) {   
  for(int i = 0; i < m; i++){
    int cont = 0;
    while(i < m && !bits(i)) {cont++; i++;}
    if(cont % 2) return false;
  }

  return true; 
}
  
ll count(int k, int x) { 
  if(k == n) return (x == 0);
  if(dp[k][x] != -1) return dp[k][x];   
  
  ll ans = 0; 
  for(int i = 0; i < (1 << m); i++) {
    if((i & x) != 0) continue; 
    if(!valid(i | x)) continue; 
    ans += count(k + 1, i);
    ans %= mod; 
  } 
  
  return dp[k][x] = ans; 
}

int main() {
  fastio;
  cin >> n >> m; 
  swap(n, m); 
  memset(dp, -1, sizeof(dp));
  cout << count(0, 0) << '\n'; 
  return 0; 
}



