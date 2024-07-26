#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 212345

typedef long long ll;

vector<ll> input;
vector<ll> result;
vector<vector<ll>> crivo;
ll n;

void read(){
	cin >> n;	
	input.resize(MAX);
	for (ll i = 0; i < MAX; i++)
		input[i] = 0;
	
	for (ll i = 0; i < n; i++){
		ll x;
		cin >> x;
		input[x]++;
	}
}

void make_crivo() {
	crivo.resize(MAX);
	for (ll i = 2; i < MAX; i++) // para cada valor i 
	{
		if (crivo[i].size() == 0) { // Se i for primo
			//crivo[i].push_back(1);
			ll num = 2*i;
			while(num < MAX) { // para cada multiplo num de i
				crivo[num].push_back(i); //crivo[4].push_back()
				num += i;
			}
		}
	}
}

void debug_crivo(){
	for(int i = 0; i < MAX; i++){
		cout << i << ": ";
		for(int j = 0; j < crivo[i].size(); j++){
			cout << crivo[i][j] << " ";
		}
		cout << endl;
	}	
}

ll solve() {
	result.resize(MAX);
	result[1] = input[1];
	
	for (ll i = 2; i < MAX; i++){
		ll res = input[1]; // res = 2.
		for (ll j = 0; j < crivo[i].size(); j++) {
			res = max(res, result[i/crivo[i][j]]);
		}
		res += input[i]; // res = 3.
		result[i] = res; // 3
	}
	ll ans = 0;
	for (ll i = 0; i < MAX; i++)
		ans = max(ans, result[i]);

	return ans;
}

int main() {
	read();
	make_crivo();
	cout << solve() << endl;
	return 0;
}

