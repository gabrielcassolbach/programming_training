#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long ll; 

#define pb push_back
#define ii pair<int, ll>
#define vi vector<ii> 
#define graph vector<vi> 
#define f first 
#define s second 

ll n, m; 
graph g;  
vector<int> vis; 

void read(){
	cin >> n >> m; g.resize(n + 10); 
	for(int i = 1; i <= m; i++) {
		int a, b; ll c;
		cin >> a >> b >> c;
		g[a].pb({b, c}); 
	}
	vis.resize(n + 10, 0);
}

int main() {
	fastio; 
	read();
	
	return 0; 
}




