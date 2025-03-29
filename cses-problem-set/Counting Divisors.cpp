#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define MAX 1123456
 
int d[MAX];
 
void eratostones() {
  for(int i = 0; i < MAX; i++) d[i] = 1;    
  for(int i = 2; i < MAX; i++) {
    if(d[i] != 1) continue;
    for(int j = i; j < MAX; j += i){
      int mult = 0;
      int tmp = j;
      while(!(tmp % i)) {
        mult++; 
        tmp /= i;
      }  
      d[j] *= (mult+1); 
    }
  } 
}
 
int main() {
  fastio;
  eratostones(); 
  int n; cin >> n;
  while(n--) {
    int val; cin >> val;
    cout << d[val] << '\n';
  }
  return 0;
}
