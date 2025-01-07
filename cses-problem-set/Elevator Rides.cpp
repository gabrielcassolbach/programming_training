// Solution based on CSES-Problem Set Book.
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 1<<20


typedef long long ll;

ll x, n; 
vector<ll> weight; 
pair<ll, ll> best[MAX];

void read() {
	cin >> n >> x;
	weight.resize(n+10);
	for(int i = 0; i < n; i++) 
		cin >> weight[i];
}

void solve() {
	best[0] = {1, 0};
	for(int s = 1; s < (1<<n); s++) {
		best[s] = {n+1, 0};	
		for(int p = 0; p < n; p++){ 
			if (s & (1 << p)) {
				auto option = best[s^(1<<p)];
				if(option.second+weight[p] <= x) {
					option.second += weight[p];
				}else{
					option.first++;
					option.second = weight[p];
				}
				best[s] = min(best[s], option);
			}
		}
	}
	cout << best[(1<<n)-1].first << '\n'; 	 
}

int main() {
	fastio;
	read();
	solve(); 
	return 0;
}


