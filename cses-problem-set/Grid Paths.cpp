#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define f first
#define s second

string s;
int m[8][8]; 
ll ans;  

char get_pos(int x) {
	char cord[4] = {'D', 'U', 'L', 'R'};
	return cord[x];
}

pair<int, int> get_cord(char c, int i, int j) {
	if(c == 'D') return {i+1, j};
	if(c == 'U') return {i-1, j};	
	if(c == 'L') return {i, j-1};
	if(c == 'R') return {i, j+1};
}

int valid(int i, int j) {
	if(i > 7 || i < 1) return 0; 
	if(j > 7 || j < 1) return 0; 
	return 1; 
}

void print_matrix() {
	for(int i = 1; i <= 7; i++){
		for(int j = 1; j <= 7; j++) {
			cout << m[i][j];
		}
		cout << '\n';
	}
}

void find_solutions(int i, int j, int pos) {
	if(!valid(i, j)) return; 
	if(pos >= 49) return;
	print_matrix();  
	cout << i << " " << j << "\n";
	if(i == 7 && j == 1 && pos == 48) 
		{ans++; return;}		

	if(s[pos] != '?') {
		pair<int, int> a = get_cord(s[pos], i, j);
		m[a.f][a.s] = 1; 	
		find_solutions(a.f, a.s, pos+1); 
	}else{
		for(int x = 0; x < 4; x++){
			char c = get_pos(x); pair<int, int> a = get_cord(c, i, j); 	
			if(valid(a.f, a.s) && !m[a.f][a.s]){
				m[a.f][a.s] = 1; 
				find_solutions(a.f, a.s, pos + 1);	
				m[a.f][a.s] = 0; 
			}
		}	
	}	
}

void init() {
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			m[i][j] = 0; 
}

int main() {
	fastio; 
	cin >> s; cout << s << '\n'; 
	init(); 
	ans = 0;  
	find_solutions(1, 1, 0);
	cout << ans << '\n';	
	return 0;
}


