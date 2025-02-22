#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
	fastio; 
	int n; cin >> n;
	map<string, int> m; 
	set<string> my_s; 
	while(n--){
		string s; cin >> s; 
		m[s]++;
		my_s.insert(s);  
	} 
	int larger = -1; string ans; 
	for(auto it = my_s.begin(); it != my_s.end(); ++it) {
		if(m[*it] > larger) { 
			larger = m[*it];
			ans = *it;
		}		
	}
	cout << ans << '\n'; 
	return 0; 
}
