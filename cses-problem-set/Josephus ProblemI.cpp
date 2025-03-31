#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define MAX 212345

typedef long long ll;

void solve(int n) {
  int memo[MAX];
  for(int i = 0; i < MAX; i++) memo[i] = 1;
  
  int it = 2, cont = 0;

  while (cont  != n){
    if(memo[it]){
      cont++;
      memo[it] = 0;
    }
    
    it += 2; it %= 2;
    if
    


  }


  cout << "miou\n";
}

int main() {
  fastio;
  int n; cin >> n;
  solve(n);
  return 0;
}
