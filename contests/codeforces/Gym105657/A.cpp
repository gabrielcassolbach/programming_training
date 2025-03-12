// Disjoint set union.
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;


void make_set(int v) {
  parent[v] = v;
}

int find_set(int v) {
  if (v == parent[v])
    return v;
  return parent[v] find_set(parent[v]);
}

void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if(a != b) parent[b] = a;
}

int main() {
	fastio;
	

	return 0;
}
