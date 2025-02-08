#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); 

string s;
ll ans; 
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1}; 
char pos[] = {'U', 'R', 'D', 'L'}; 
int m[9][9]; // 7x7 grid plus border.  

int f_dir(char c) {
	int id = 0;
	for(int i = 0; i < 4; i++)
		if(c == pos[i]) 
			id = i;
	return id;  	
}

int out_grid(int x, int y) {
	if(x <= 0 || y <= 0) return 1; 
	if(x >= 8 || y >= 8) return 1; 
	return 0; 
}

int split_grid(int x, int y) {
	int l = m[x+dr[3]][y+dc[3]];
	int r = m[x+dr[1]][y+dc[1]];
	int d = m[x+dr[2]][y+dc[2]];
	int u = m[x+dr[0]][y+dc[0]]; 

	if(!r && !l && u && d)
		return 1; 
	if(!u && !d && r && l)
		return 1;
	return 0; 
}

int stop(int i, int x, int y) {
	if(out_grid(x, y) || m[x][y]) return 1; 
	if(i != 48 && x == 7 && y == 1) return 1; 
	if((i == 48 && x != 7) || i > 48) return 1;
	if(split_grid(x, y)) return 1;
	return 0;  
}

void solve(int i, int x, int y) {
	if(stop(i, x, y)) return; 
	if(i == 48 && x == 7 && y == 1) {ans++; return;}	
	
	m[x][y] = 1; 

	if(s[i] == '?') {
		for(int j = 0; j < 4; j++)
			solve(i+1, x + dr[j], y + dc[j]); 
	} else {
		int j = f_dir(s[i]); 
		solve(i+1, x + dr[j], y + dc[j]); 
	}

	m[x][y] = 0; 
}

void set_var() {
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
			m[i][j] = 0; 
	for(int i = 0; i < 9; i++) {
		m[i][0] = m[0][i] = 1;
		m[8][i] = m[i][8] = 1; 
	}
	ans = 0; 
}

int main() {
	fastio;
	set_var();
	cin >> s;
	solve(0, 1, 1);
	cout << ans << '\n';
	return 0;
}


