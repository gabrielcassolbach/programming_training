#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second 
#define pb push_back

typedef long long ll;

const int MAX = 1e9 + 7; 

vector<int> v;
map<int, int> hash_m, hash_print; // {value, key}.  
int n, k;

void answer(int ans, int q) {
  if (ans == n) 
    {cout << -1 << '\n'; return;}
  cout << ans << '\n';
  
  int it = 1;
  while(it <= n) {
    hash_print[it++] = 1;
    first_v += q;
  }
    
  for(int i = 1; i <= n; i++){
    if(hash_print[v[i]] == 0)

  }

  cout << '\n';
}

void solve() {
  int a = v[1], b = v[n];
  int ans = n; int q = MAX;

  while(a <= b){
    int c = (a + b)/2;
    int cnt = 1, aux_k = 0;
    //cout << "a: " << a << " b: " << b << '\n'; 
    //cout << "c: " << c << '\n';
    auto it = hash_m.find(v[cnt] + c);
    aux_k += (it == hash_m.end()) ? (n - cnt) : 0; 

    while(it != hash_m.end()) {  
      aux_k += hash_m[v[cnt] + c] - cnt - 1;
      cnt = hash_m[v[cnt] + c];
      it = hash_m.find(v[cnt] + c);
      aux_k += (it == hash_m.end()) ? (n - cnt) : 0; 
    }

    if(aux_k <= k) {
      ans = min(ans, aux_k);
      q = min(q, c);
      a = c + 1;
    }else{
      b = c - 1;
    }

    //cout << "aux_k: " << aux_k << '\n';
  }

  answer(ans, q);
}

int main() {
  fastio;   
  cin >> n >> k; 
  v.resize(n + 1);
  for(int i = 1; i <= n; i++){
    cin >> v[i]; 
    hash_m[v[i]] = i;
  }
  solve();
  return 0;
}
