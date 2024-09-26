#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back

typedef long long ll;

vector<ll> a, b;
ll n;

void print_ans(){
	cout << "YES" << '\n';
	cout << a.size() << '\n';
	for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
	cout << '\n' << b.size() << '\n';
	for(int i = 0; i < b.size(); i++) cout << b[i] << " ";	
	cout << '\n';
}

void divide(ll sum) {
	ll sum_a = 0, sum_b = 0;
	
	for(int i = n; i >= 1; i--) {
		if(sum_a < sum_b){
			sum_a += i;
			a.pb(i);
		}else{
			sum_b += i;
			b.pb(i);
		}
	}
	if(sum_a == sum_b)
		print_ans();
	else 
		cout << "NO\n";
	return;		
}

int main(){
	fastio;
	cin >> n;
	ll sum = ((n + 1)/2)*n;  
	if(sum % 2) cout << "NO" << '\n'; 	
	else divide(sum);
    return 0;
}

