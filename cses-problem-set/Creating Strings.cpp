#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 10

typedef long long ll;

set<string> q;
string s; ll counter;
vector<char> permutation;
bool chosen[MAX];

void search() {
	if(permutation.size() == s.size()){
		string a = ""; 
		for(int i = 0; i < permutation.size(); i++)
			a += permutation[i];
		q.insert(a);	
	}else{
		for(int i = 0; i < s.size(); i++){
			if(chosen[i]) continue;
			chosen[i] = true;
			permutation.push_back(s[i]);			
			search();
			chosen[i] = false;
			permutation.pop_back();
		}
	}	
}

void init() {
	counter = 0;
	sort(s.begin(), s.end());
	for(int i = 0; i < MAX; i++)
		chosen[i] = 0;
}

void answer() {
	cout << q.size() << '\n';
	for(auto it = q.begin(); it != q.end(); it++)
		cout << (*it) << '\n';	
}

int main() {
	fastio;
	cin >> s; 
	init(); search(); answer();
	return 0;
}



