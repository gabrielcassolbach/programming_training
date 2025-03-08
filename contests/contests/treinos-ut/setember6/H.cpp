#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

int main() { _
	ll ca, ba, pa; cin >> ca >> ba >> pa;
	ll cr, br, pr; cin >> cr >> br >> pr;
	ll ans = 0;	

	if(ca < cr) ans += (abs(ca-cr));
	if(ba < br) ans += (abs(ba-br));
	if(pa < pr) ans += (abs(pa-pr));

	cout << ans << '\n';
	return 0;
}
