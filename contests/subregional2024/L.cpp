#include <bits/stdc++.h>
using namespace std;

#define MAX 32
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int n;
int bits[MAX];

void read(){
	cin >> n;
	for(int i = 0; i < MAX; i++) bits[i] = 0;
}

void getBits(){
	for (int i = 0; i < n; i++){
		int x; cin >> x;
		for(int j = 0; j < MAX; j++){
			if(x & (1 << j)) bits[j]++;
		}
	}
}

void solve(){
	getBits();
	for(int k = 0; k < n; k++){
		int val = 0; 
		for(int i = 0; i < MAX; i++) {
			if(bits[i]){
				val += (1 << i);	
				bits[i]--;
			}
		}
		cout << val << " ";
	}	
	cout << '\n';
}

int main() { _
	read();
	solve();
	return 0;
}
