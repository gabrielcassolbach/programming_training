#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m;
vector<vector<ll>> matrix, matrix_t;

void read(){
	cin >> n >> m;
	matrix.resize(n + 3, vector<ll> (m + 3));
	matrix_t.resize(m + 3, vector<ll> (n + 3));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> matrix[i][j];
			matrix_t[j][i] = matrix[i][j];
		}
	}
}

void answer(){
	ll ans = 1, ld_tmp, cd_tmp; 
	for(int i = 1; i <= n; i++){
		ld_tmp = 1; 
		for(int j = 1; j <= m-1; j++){
			if(abs(matrix[i][j] - matrix[i][j+1]) <= 1)
				ld_tmp++;
			else
				ld_tmp = 1;
			ans = max(ans, ld_tmp);
		}
	}

	for(int i = 1; i <= m; i++){
		cd_tmp = 1; 
		for(int j = 1; j <= n-1; j++){
			if(abs(matrix_t[i][j] - matrix_t[i][j+1]) <= 1)
				cd_tmp++;
			else
				cd_tmp = 1;
			ans = max(ans, cd_tmp);
		}
	}

	cout << ans << endl;
}

int main(){
	read();
	answer();
	return 0;
}
