/* This solution was implemented using the code in the site: https://cp-algorithms.com/sequences/longest_increasing_subsequence.html as an example.*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

ll lis(vector<ll> const& a, ll n) {
	const ll INF = 1e9; vector<ll> d(n + 1, INF);
	d[0] = -INF;
	
	// i = 3.
	for(int i = 0; i < n; i++){
		ll l = upper_bound(d.begin(), d.end(), a[i]) - d.begin(); // logn.
		if(d[l-1] < a[i] && a[i] < d[l])
			{d[l] = a[i];}
	}
		
	for(int l = 0; l <= n; l++)
		cout << d[l] << " ";
	cout << endl;

	ll ans = 0;
	for(int l = 0; l <= n; l++)
		if(d[l] < INF)
			ans = l;

	return ans;
}

int main() { _
	ll n; cin >> n;;
	vector<ll> a(n+1);
	for(int i = 0; i < n; i++) cin >> a[i];	
	cout << lis(a, n) << endl;
	return 0;
}
