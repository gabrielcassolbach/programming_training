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
  if (ans == n) {cout << -1 << '\n'; return;}
  if(!ans) {cout << ans << '\n'; return;}

  cout << ans << '\n';
  int cnt = 1; hash_print[cnt] = 1;
 
  auto it = hash_m.find(v[cnt] + q);
  while(it != hash_m.end()){
    cnt = hash_m[v[cnt] + q];
    hash_print[cnt] = 1;
    it = hash_m.find(v[cnt] + q);
  }

  for(int i = 1; i <= n; i++)
    if(!hash_print[i]) cout << i << " ";
  cout << '\n';
}

void solve() {
  int a = v[1], b = v[n];
  bool increasing = (v[n] > v[1]);
  if(!increasing) swap(a, b);
  int ans = n; int q = increasing ? MAX : -MAX;

  cout << a << " " << b << '\n';

  int debug1 = 0, debug2 = 0;

  while(a <= b){
    debug1++;
    cout << "aqui1\n";
    int c = increasing ? abs((a + b)/2) : (a + b)/2;
    int cnt = 1; ll aux_k = 0;
    cout << "a: " << a  << " b: " << b << "\n";
    cout << "-------------->c: " << c << '\n';

    auto it = hash_m.find(v[cnt] + c);
    aux_k += (it == hash_m.end()) ? (n - cnt) : 0; 

    while(it != hash_m.end()) {  
      aux_k += hash_m[v[cnt] + c] - cnt - 1;
      if(c == 2) cout << cnt << " ";
      cnt = hash_m[v[cnt] + c];
      it = hash_m.find(v[cnt] + c);
      aux_k += (it == hash_m.end()) ? (n - cnt) : 0; 
    }
    cout << "aux_k: " << aux_k << "\n";
    debug2 = 0;
    if(aux_k <= k) {
      cout << "--> a\n";
      ans = min((ll)ans, aux_k);
      q = increasing ? min(q, c) : max(q, c);  
      if(increasing)
        a = c + 1;
      else 
        b = c - 1;
    }else{
      cout << "--> b\n";
      if(increasing)
        b = c - 1;
      else 
        a = c + 1;
    }
  }

  answer(ans, q);
}

int main() {
  fastio;   
  cin >> n >> k; cout << "teste: " << n << " " << k << "\n";
  v.resize(n + 1);
  for(int i = 1; i <= n; i++){
    cin >> v[i]; 
    hash_m[v[i]] = i;
  }
  solve();
  return 0;
}
