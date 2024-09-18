#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 512
#define graph vector<vector<pair<ll, ll>>> 
#define pb push_back

const ll INF = 1e15 + 10;

ll n, m, q;
ll dist[MAX][MAX];
graph g;

void setGraph(){
    cin >> n >> m >> q;
	g.resize(n + 10);
    while(m--){
        ll city1, city2, d;  
        cin >> city1 >> city2 >> d; 
       	g[city1].pb({d, city2});
		dist[city1][city2] = min(dist[city1][city2], d);
		dist[city2][city1] = min(dist[city2][city1], d);
    }   
}

void initDistance() {
	for(int i = 1; i < MAX; i++){
		for(int j = 1; j < MAX; j++) {
			if(i == j) dist[i][j] = 0;	 
			else dist[i][j] = INF;
		} 
	}
}

void floydWarshall() {
	for(int k = 1; k <= n; k++) 
		for(int i = 1; i <= n; i++) 
			for(int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

void solve() {
	floydWarshall();    
	while(q--) {
		int a, b; cin >> a >> b;
		if(dist[a][b] == INF) 
			cout << -1 << '\n';
		else
			cout << min(dist[a][b], dist[b][a]) << '\n';
	}
}

int main() { _
	initDistance();
    setGraph();
	solve();
    return 0;
}
