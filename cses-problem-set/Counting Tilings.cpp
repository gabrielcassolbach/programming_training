#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define MAX 11
#define MAX2 1001
#define f first
#define s second

const int mod = 1e9 + 7; 

int main() {
  fastio; 
  cin >> n >> m; 
  memset(dp, -1, sizeof(dp)); 
  cout << count(m, 1).f << '\n';
  return 0; 
}




