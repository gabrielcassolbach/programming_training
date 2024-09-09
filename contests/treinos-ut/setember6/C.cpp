#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 1123

typedef long long ll;

ll x, n;
ll freq[MAX]; ll cnt[MAX];

void read(){
	cin >> x >> n; 
	for(int i = 0; i < MAX; i++) {cnt[i] = freq[i] = 0;}
}

int allEqual(){
	int val = cnt[1];
	for(int i = 1; i <= x; i++){
		if(cnt[i] != val) return 0;
	}
	return 1;
}

int simulate(char key){
	for(int i = 1; i <= x; i++){
		cnt[i] += (key == '+')? +1 : -1;
		if(allEqual()){
			cout << key << i << '\n';
			return 1;	
		}
		cnt[i] += (key == '+')? -1 : +1;
	}
	return 0;
}


int main() { _
	read();
	for(int i = 0; i < n; i++) {
		ll val; cin >> val;
		cnt[val]++;
	}
	if(simulate('+')) return 0; 
	if(simulate('-')) return 0;
 
	for(int i = 1; i <= x; i++){
		freq[cnt[i]]++;
	}


	for(int i = 1; i <= x; i++){
		if(freq[cnt[i]] == 1 && freq[cnt[i] + 1] == x-2){
		for(int j = 1; j <= x; j++){
			if(freq[cnt[j]] == 1 && cnt[j] == cnt[i] + 2){
				cout << "-" << j << " " << "+" << i << '\n';
				return 0;
			}
		}
		}
	}
	cout << "*" << '\n';

	return 0;
}
