#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;

map<ll, ll> m;
vector<ll> v;
ll n;

void read() {
	cin >> n; v.resize(n + 10);
	for(int i = 0; i < n; i++)
		cin >> v[i];
}

ll solve(){
	ll ans = 1;
	m.insert({v[0], 0});
	ll beg_index = 0;
	for(int i = 1; i < n; i++) {
		auto it = m.find(v[i]);
		if(it != m.end()) {	
			beg_index = max((*it).second + 1, beg_index);
			(*it).second = i;
		}else{
			m.insert({v[i], i});
		}
		ans = max(ans, i - beg_index + 1);
	}
	return ans;
}

int main() { _
	read();
	cout << solve() << endl;
	return 0;
}
