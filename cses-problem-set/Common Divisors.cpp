#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define MAX 1123456

int input[MAX];

int main() {
  fastio; 
  int n; cin >> n;
  memset(input, 0, sizeof input); 
  for(int i = 0; i < n; i++){
    int val; cin >> val;
    input[val]++;
  }

  int ans = 1; 
  for(int i = 2; i < MAX; i++){
    int cont = 0;
    for(int j = i; j < MAX; j += i) {
      cont += input[j];
    } 
    if(cont >= 2) ans = i; 
  }  

  cout << ans << '\n';
  return 0;
}
