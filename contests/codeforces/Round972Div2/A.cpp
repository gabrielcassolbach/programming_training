#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


char vowels[5] = {'u', 'o', 'i', 'e', 'a'};
int vowelsfreq[5];

void solve(int n) {
	for(int i = 0; i < 5; i++)  vowelsfreq[i] = 0;
	for(int i = 0; i < n; i++)  vowelsfreq[(i)%5]++;
	
	string s = "";
	for(int i = 0; i < 5; i++){
		while(vowelsfreq[i]){
			s += vowels[i];
			--vowelsfreq[i];
		}
	}
	
	cout << s << '\n';
}

int main() { _
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		solve(n);
	}
	return 0;
}	
