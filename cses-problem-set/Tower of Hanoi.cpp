#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;
queue<pair<int, int>> q;

			//              1         3        2
int hanoi_tower(int n, int from, int to, int aux){
	if(n == 0) return 0;
	int sum = 0;
	sum += hanoi_tower(n-1, from, aux, to); 
	q.push({from, to}); sum++;
	sum += hanoi_tower(n-1, aux, to, from);
	return sum;
}

int main() {
	fastio;
	int n; cin >> n;
	cout << hanoi_tower(n, 1, 3, 2) << '\n';; 
	while(!q.empty()) {
		pair<int, int> p; p = q.front();
		cout << p.first << " " << p.second << '\n';
		q.pop();
	}
	return 0;
}
