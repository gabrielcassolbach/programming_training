#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define MAX 27

string s1, s2, s3; 
int parent[MAX];

void make_set(int v) {
  parent[v] = v;
}

int find_set(int v) {
  if (v == parent[v])
    return v;
  return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if(a != b) parent[b] = a;
}

void debug() {
  for(int i = 1; i < MAX; i++) 
    cout << parent[i] << " ";
  cout << "\n";
}

string solve() {
  for(int i = 0; i < MAX; i++) parent[i] = 0;
  cin >> s1 >> s2 >> s3;   
  
  if(s1.size() != s2.size()) return "NO";
  if(s1.size() == s2.size() && s1.size() != s3.size()) return "YES";

  for(int i = 0; i < (int) s1.size(); i++) {
     make_set(s1[i] - 'a' + 1);
     make_set(s2[i] - 'a' + 1);
  }
  
  int it = 2;
  while(it--) {
    for(int i = 0; i < (int) s1.size(); i++) {
      int val1 = s1[i] - 'a' + 1; int val2 = s2[i] - 'a' + 1;
      union_sets(min(val1, val2), max(val1, val2));
    }
  }

  string f1 = "", f3 = "";
  for(int i = 0; i < (int) s1.size(); i++){
    f1 += parent[s1[i] - 'a' + 1] + '0';  
    f3 += parent[s3[i] - 'a' + 1] + '0';  
  } 


  return (f1 != f3) ? "YES" : "NO";
}

int main() {
	fastio;
  int t; cin >> t; 
  while(t--) {
    cout << solve() << '\n';
  }
	return 0;
}



