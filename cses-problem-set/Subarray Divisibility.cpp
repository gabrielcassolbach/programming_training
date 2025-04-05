#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;

ll n; vector<ll> v;

ll solve(){
	ll ans = 0;
	if(n == 1) return 1;  
	vector<ll> p_s, freq; 
	p_s.resize(n); freq.resize(n+1, 0);

	p_s[0] = v[0];
	for(int i = 1; i < n; i++)
		p_s[i] = p_s[i-1] + v[i];

	for(int i = 0; i < n; i++){
		p_s[i] = ((p_s[i]%n) + n)%n;
		freq[p_s[i]]++;
	}

	ans += freq[0];
	for(int i = 0; i <= n; i++) {
		if(freq[i] > 1) 
			ans += (freq[i]*(freq[i]-1))/2;
	}
	
	return ans;
}

int main() { 
	fastio;
	cin >> n; v.resize(n);
	for(int i = 0; i < n; i++) 
		cin >> v[i];
	cout << solve() << '\n';
	return 0;
}


