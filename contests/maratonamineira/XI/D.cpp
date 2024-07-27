#include <bits/stdc++.h>
using namespace std;

int n, l;
vector<int> v;

void read(){
	cin >> n >> l; v.resize(n + 10);
	for(int i = 0; i < n; i++)
		cin >> v[i];
}

void solve(){
	int ans = 0;
	sort(v.begin(), v.end(), greater<int> ());
	for(int i = 0; i < n && l; i++){
		if(100 - v[i] >= 0 && l >= 100 - v[i]){
			l -= (100 - v[i]);
			ans++;
		}
	}
	cout << ans << endl;
}

int main(){
	read();
	solve();
	return 0;
}
