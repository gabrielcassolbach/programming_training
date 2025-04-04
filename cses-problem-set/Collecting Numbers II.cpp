#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long ll; 

vector<int> pos; 
vector<int> v; 
int n, m, ans;

int solve(int pos_a, int pos_b) {
  int a = v[pos_a]; int b = v[pos_b];
  map<int, bool> m;  
 
  set<int> s; s.insert({a, b}); 
  if(a + 1 < n) s.insert(a+1);
  if(b + 1 < n) s.insert(b+1);

  for(auto val : s)
    m[val] = (val == 0) ? true : pos[val-1] > pos[val];      
  
  swap(v[pos_a], v[pos_b]); 
  pos[a] = pos_b; pos[b] = pos_a; 

  for(auto val : s)
    ans +=  ((val == 0) ? true : pos[val-1] > pos[val]) - m[val];
  
  return ans;
}

int main() {
  fastio; 
  cin >> n >> m; 
  v.resize(n); pos.resize(n, 0);
  for(int i = 0; i < n; i++) { 
    cin >> v[i]; 
    pos[--v[i]] = i; 
  }
  ans = 1;
  for(int i = 1; i < n; i++)
    if(pos[i-1] > pos[i]) 
      ans++; 

  while(m--){
    int a, b; cin >> a >> b;
    cout << solve(--a, --b) << '\n';
  } 
  return 0;
}

