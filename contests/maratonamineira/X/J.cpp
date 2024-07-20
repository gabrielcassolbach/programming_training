#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define MAX 512
#define MAX2 51234

/*dynamic-programming approach */

typedef long long ll;

struct k_peia {
	ll k;
	ll t;
	ll m;
};

struct sapato {
	ll e;
	ll d;
};

vector<k_peia> v_ax;
vector<pair<ll, ll>> g; 
k_peia v[MAX];
sapato a[MAX]; 
ll m[MAX][MAX2];
int n, t;

void read(){
	cin >> n >> t;
	for(int i = 1; i <= n; i++)
		cin >> v[i].k >> v[i].t >> v[i].m;	
	for(int i = 1; i <= t; i++)
		cin >> a[i].e >> a[i].d;	
}

ll pd(ll item, ll lim){
	g.push_back({item, lim});
	if(!item or !lim)
		{m[item][lim] = 0; return m[item][lim];}
	if(m[item][lim] != -1)
		{return m[item][lim];} 
	if(lim < (v_ax[item-1].k/2))
		{m[item][lim] = pd(item-1, lim);}
	else
		{m[item][lim] = max(pd(item-1, lim), pd(item-1, lim-(v_ax[item-1].k/2)) + v_ax[item-1].m);}
	return m[item][lim];
}

void garbage_colector(){
	for(int i = 0; i < g.size(); i++)
		m[g[i].first][g[i].second] = -1;
	g.clear();
}

ll best_choice(int i, ll lim){ 
	v_ax.clear();
	garbage_colector();
	for(int j = 0; j <= n; j++){
		if(v[j].t == i) v_ax.push_back(v[j]);
	}
	return pd(v_ax.size(), lim);
}

void init_memo(){
	for(int i = 0; i < MAX; i++)
		for(int j = 0; j < MAX2; j++)
			m[i][j] = -1;
}

void answer(){
	ll ans = 0;
	for(int i = 1; i <= t; i++) {
		ll lim = min(a[i].e, a[i].d);
		ans += best_choice(i, lim);
	}
	cout << ans << endl;
	return;
}

int main(){
	read();
	init_memo();
	answer();
	return 0;
}
