#include <bits/stdc++.h>
using namespace std; 
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define MAX 9
#define f first
#define s second 
 
// {down, right, left, up}
int dr[] = {1, 0, 0, -1};
int dc[] = {0, 1, -1, 0};
int c[] = {'D', 'R', 'L', 'U'};
int grid[MAX][MAX]; 
int ans;
string s;
 
int split_grid(int it, int i, int j) {
  int r = grid[i][j+1]; int l = grid[i][j-1];
  int u = grid[i-1][j]; int d = grid[i+1][j];
 
  if(!r && !l && u && d) return 1; 
  if(!u && !d && r && l) return 1;  
  //if(d && r && !grid[i+1][j+1]) return 1;
  //if(d && l && !grid[i+1][j-1]) return 1;
  //if(u && l && !grid[i-1][j-1]) return 1;
  //if(u && r && !grid[i-1][j+1]) return 1;
 
  return 0;
}
 
int solve(int it, int i, int j) {
  if(split_grid(it, i, j)) return 0;
  if(i == 7 && j == 1) {
    if(it == 48) return 1; 
    return 0;
  }  
  if(it == 48) return 0; 
  int ans = 0;
  
  grid[i][j] = 1;  
  for(int k = 0; k < 4; k++) {
    if(!grid[i + dr[k]][j + dc[k]] && (s[it] == '?' || s[it] == c[k]))
      ans += solve(it + 1, i + dr[k], j + dc[k]);
  } 
  
  grid[i][j] = 0; 
  return ans;
}
 
int main() {
  fastio; 
   cin >> s;
  for(int i = 0; i < MAX; i++){
    grid[i][0] = grid[0][i] = 1;
    grid[8][i] = grid[i][8] = 1; 
  } 
  for(int i = 1; i <= 7; i++)
    for(int j = 1; j <= 7; j++)
      grid[i][j] = 0;
  ans = solve(0, 1, 1);
  cout << ans << '\n';
  return 0; 
}


 
