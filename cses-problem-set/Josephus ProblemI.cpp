#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(false);
 
#define MAX 212345
 
void solve(int n) {
  queue<int> q; int flag = false;
  for(int i = 1; i <= n; i++)
    q.push(i);
  
  while(!q.empty()) {
    int val = q.front();  
    q.pop();
 
    if(flag) 
      cout << val << " ";     
    else
      q.push(val);
   
    flag = !flag;
  }
}
 
int main() {
  fastio; 
  int n; cin >> n;
  solve(n); 
  cout << '\n';
  return 0;
}
 