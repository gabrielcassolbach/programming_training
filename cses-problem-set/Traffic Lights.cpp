#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define in insert

multiset<ll> mts;
set<ll> s;

ll n, x;

void init_sets() {
	s.in(0); s.in(x);
	mts.in(x-0);
}

void debug_mts() {
	cout << "debugging: ";
	for(auto it = mts.begin(); it != mts.end(); it++)
		cout << (*it) << " ";
	cout << '\n';
}

void solve() {
	cin >> x >> n;
	init_sets();
	while(n--) {
		ll val; cin >> val;
		s.in(val);
		auto it = s.find(val); 		
		int prev_elem = *prev(it); int next_elem = *next(it);
		mts.erase(mts.find(next_elem - prev_elem));
		mts.in(val - prev_elem); mts.in(next_elem - val); 
		//debug_mts(); 
		cout << *mts.rbegin() << " ";
	} 
	cout << '\n';
}	

int main() {
	fastio;
	solve(); 
	return 0;
}
 
