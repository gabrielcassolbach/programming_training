#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
#define MAX 5123

typedef long long ll;

const ll INF = 1e14 + 10;

string a, b;
ll dp[MAX][MAX];

ll solve(string a, string b){
	for(int i = 1; i <= a.size(); i++) {
		for(int j = 1; j <= b.size(); j++) {
			if(a[i-1] == b[j-1])
				dp[i][j] = dp[i-1][j-1];
			else	
				dp[i][j] = min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j])) + 1;		
		}
	}
	return dp[a.size()][b.size()]; 
}

void init() {
	for(int i = 0; i < MAX; i++)
		for(int j = 0; j < MAX; j++)
			dp[i][j] = INF;

	for(int i = 0; i <= a.size(); i++) dp[i][0] = i;
	for(int i = 0; i <= b.size(); i++) dp[0][i] = i;
}	

int main() { 
	fastio;
	cin >> a >> b; init();
	cout << solve(a, b) << '\n';
	return 0;
}



