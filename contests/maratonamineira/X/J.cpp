#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 504

/*brute-force approach*/

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

k_peia v[MAX];
sapato a[MAX]; 
int n, t;

void read(){
	cin >> n >> t;
	for(int i = 1; i <= n; i++)
		cin >> v[i].k >> v[i].t >> v[i].m;	
	for(int i = 1; i <= t; i++)
		cin >> a[i].e >> a[i].d;	
}

ll best_choice(int i, ll lim){
	vector<k_peia> v_ax; 
	for(int j = 1; j <= n; j++)
		if(v[j].t == i) v_ax.push_back(v[j]);
		
	sort(v_ax.begin(), v_ax.end(), [](k_peia& one, k_peia& two){return one.k < two.k;}); 
	ll best_choice = 0; int j = 0;
	while(j < n){
		ll choice = 0; ll aux_lim = lim;
		for(int l = j; l < v_ax.size(); l++){
			if(v_ax[l].k/2 <= aux_lim){
				aux_lim -= v_ax[l].k/2;
				choice += v_ax[l].m;
			} 
		}
		best_choice = max(best_choice, choice);
		j++;
	}	
			
    v_ax.clear();	
	return best_choice;
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
	answer();
	return 0;
}


