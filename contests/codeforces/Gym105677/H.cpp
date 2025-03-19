#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define s second
#define f first 
typedef long long ll; 

vector<int> g; // iremos salvar a resposta aqui. 
vector<pair<int, int>> path;
int n, k;

void read() {
	cin >> n >> k;
	g.clear(); g.resize(n + 1, 0);
	path.clear(); 
	for(int i = 0; i < k; i++) {
		int l, r; cin >> l >> r;  
		for(int j = l + 1; j <= r; j++) 
			g[j] = j - 1;
		path.pb({(r - l + 1), l}); 
	}	
}

int solve() {
	sort(path.begin(), path.end());
	
	vector<int> cap(path.back().f); iota(cap.begin(), cap.end(), 0);  
	vector<int> dcap(path.back().f + 1, 0); 
	int it = 0; 

	for(int i = 0; i < (int)path.size() - 1; i++) {
		while(it < (int)cap.size() && cap[it] < path[i].f) {
			it++;
			if(it == (int) cap.size()) return 0; 
			dcap[it] += dcap[it-1];
			cap[it] += dcap[it];
		}	
		int r = path.back().s + path.back().f - 1; 
		g[path[i].s] = r - it;
		dcap[it+1] += path[i].f;  	
	}	

	return 1; 
}

int main() {
	fastio;
	int t; cin >> t;
	while(t--) {
		read();
		int ans = solve();
		if(!ans) cout << "IMPOSSIBLE\n";
		else {
			for(int i = 1; i <= n; i++)
				cout << g[i] << " ";
			cout << "\n";
		}			
	}	
	return 0;
}


