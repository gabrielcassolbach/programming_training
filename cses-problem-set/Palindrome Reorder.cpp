#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 1123456
#define in insert

typedef long long ll;

string s;
int freq[MAX];
int even, odd;
map<char, int> letters;


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

bool hasSolution() {
	if(s.size() % 2 && (odd > 1 || odd == 0))
		return false;	
	if(!(s.size() % 2) && odd > 0)
		return false;
	return true;
}

void setLetters() {
	for(int i = 0; i < s.size(); i++)
		letters[s[i]] = 0;
	for(int i = 0; i < s.size(); i++) {
		if(letters[s[i]] == 0)
			letters[s[i]] = freq[s[i]];
	}		
}

void solve() {
	queue<char> q1; stack<char> p; char l; int flag = 0;
	for(auto it = letters.begin(); it != letters.end(); it++){
		if((*it).second % 2) {flag = (*it).second; l = (*it).first; continue;}
		for(int i = 0; i < (*it).second/2; i++)
			q1.push((*it).first);
		for(int i = (*it).second/2; i < (*it).second; i++)
			p.push((*it).first);
	}
	while(!q1.empty()) {cout << q1.front(); q1.pop();}	
	while(flag) {cout << l; flag--;}
	while(!p.empty()) {cout << p.top(); p.pop();}
	return;
}

int main() {
	fastio;
	cin >> s;
	count();
	if(!hasSolution()) 
		{cout << "NO SOLUTION" << '\n'; return 0;}
	setLetters();
	solve();
	return 0;
}






