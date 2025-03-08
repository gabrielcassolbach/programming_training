#include <bits/stdc++.h>
using namespace std;

vector<int> v, ans;
int n;

void read(){
	cin >> n;
	v.resize(n+3); ans.resize(n+3);
	v[0] = -1;
	for(int i = 1; i <= n-1; i++)
		cin >> v[i];
}

void set_answer(){
	int sum = 0;
	for(int i = 1; i <= n-1; i++) 
		sum += v[i];
	int count = 0; int elem = sum % n; int val = 0;
	while(count < n){
		ans[elem] = (val > 20) ? -1 : val;
		elem++; val++; 
		elem = elem % n;
		count++;
	}
}

int main(){
	read();
	set_answer();
	for(int i = 0; i < n; i++)
		cout << ans[i] << endl;
	return 0;
}

