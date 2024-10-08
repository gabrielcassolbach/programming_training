#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define MAX (1 << 20) + 10
typedef long long ll;

int val[26];
int qt[MAX];

int main(){ _
	int at = 0;

	for (char c = 'a'; c <= 'z'; c++)
	{
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') continue;
		val[c - 'a'] = at++;
	}

	ll n; cin >> n; 
	string s; cin >> s;
	
	qt[0] = 1;
	int mask = 0;
	ll ans = 0;

	for (int i = 0; i < n; i++)
	{
		mask ^= (1 << val[(s[i] - 'a')]);
		ans += qt[mask];
		for (int j = 0; j < 20; j++)
		{
			ans += qt[mask ^ (1 << j)];
		}
		qt[mask]++;
	}

	cout << ans << endl;

	return 0;
}


/* 10100 */
