/* BIT  */

#include <bits/stdc++.h>
using namespace std;

#define MAX 31234

int n, a[MAX];
vector<int> bit[MAX];

void _add(int i, int x) {
	while(i <= n) {
		bit[i].push_back(x);
		i += i & -i;
	}
}

int _query(int i, int k) {
	int ans = 0;
	while(i > 0) {
		ans += bit[i].end() -
			upper_bound(bit[i].begin(), bit[i].end(), k);
		i -= i & -i;
	}
	return ans;
}

int main() {
	int i, j, k, q; 
	scanf("%d %d", &n, &q); 
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		_add(i, a[i]);
	}
	for (i = 1; i <= n; i++)
		sort(bit[i].begin(), bit[i].end());
	
	while(q--){
		scanf("%d %d %d", &i, &j, &k);
		printf("%d\n", _query(j, k) - _query(i - 1, k));
	}
	return 0;
}
