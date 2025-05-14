#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

vector<int> v; 
map<int, int> hash_m; // {value, key}.  
int n, k;

void answer(int ans) {
  /*cout << "answer: "; 
  cout << ans << '\n';*/
}

void solve() {
  int a = 0; int b = v[n] - v[1];
  int ans = n; int debug = 0;
  
  /*while(a <= b){
    int c = (a + b)/2;*/
    int c = 2; // razão. -> será testada em cada iteração da busca binária.
    int cnt = 1, aux_k = 0;

    auto it = hash_m.find(v[cnt] + c);
    while(it != hash_m.end()) {  
      cout << "cnt: " << cnt << '\n';
      aux_k += hash_m[v[cnt] + c] - cnt - 1;
      cnt = hash_m[v[cnt] + c];
      it = hash_m.find(v[cnt] + c);
    }
    cout << "testing: " <<  aux_k << '\n';
    cout << "aqui: " << hash_m[cnt] << '\n';
    aux_k += n - hash_m[cnt];

  
    cout << "aux_k: " << aux_k << '\n';
  //}
  
  answer(ans > k ? -1 : ans);
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
