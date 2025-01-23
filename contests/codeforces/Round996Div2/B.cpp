#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); 
#define MAX 212345

typedef long long ll; 

const ll INF = 1e12 + 10; 

/*
4
0 5 5 1 -> tenho.

1 4 4 0 -> quero.

1 0 1 1

0 1 0 0
--------




1 5 5 1
1 4 4 0

ans = [-1 1 1 1]

min(positive(values)) = 1. 

ans = [-1 -1 2] 

abs(sum(negative_values)) <= min(positive(values))


1 1 3 
1 1 2 


 */

ll n; 
ll a[MAX], b[MAX], c[MAX];   

string solve() {
	memset(c, 0, sizeof c); 
	ll min_pos = INF, pos_neg = -1; 

	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i]; 
	for(int i = 0; i < n; i++) {
		c[i] = a[i] - b[i];
		if(c[i] >= 0)
			min_pos = min(c[i], min_pos);
		if(pos_neg != -1 && c[i] < 0)
			{return "NO\n";}
		if(c[i] < 0)
			pos_neg = i;   
	}
	//cout << c[pos_neg] << " " << min_pos << '\n';	
	if(pos_neg == -1 || abs(c[pos_neg]) <= min_pos) return "YES\n"; 	 
	return "NO\n"; 
}

int main() {
	fastio; 
	int t; cin >> t; 			
	while(t--) {
		cin >> n; 
		cout << solve(); 	
	}
	return 0; 
}



