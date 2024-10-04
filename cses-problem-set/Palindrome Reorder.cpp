#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 1123456

typedef long long ll;

string s;
int freq[MAX];
int even, odd;


void count() {
	even = odd = 0;
	for(int i = 0; i < MAX; i++) freq[i] = 0;
	for(int i = 0; i < s.size(); i++)
		freq[s[i]]++;
	for(int i = 0; i < MAX; i++){
		if(!freq[i]) continue;
		if(freq[i] % 2) odd++;
		else even++;
	}
}

void hasSolution() {
	if(s.size() % 2 && (odd > 1 || odd == 0))
		return false;	
	if(!(s.size() % 2) && odd > 0)
		return false;
	return true;
}

void solve() {
	for(int i = 0; i < 	

}

int main() {
	fastio;
	cin >> s;
	count();
	if(!hasSolution()) 
		{cout << "NO SOLUTION" << '\n'; return;}
	solve();
	return 0;
}






