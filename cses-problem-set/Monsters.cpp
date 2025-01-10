#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 1123
#define INF 112345678
#define f first
#define s second
#define pb push_back

ll n, m; 
vector<pair<int, int>> sources; 
vector<pair<int, int>> solutions;
pair<bool, pair<char, int>> matrix[MAX][MAX]; // <'A', 0>

int isSource(int i, int j, char pto) {
	if(pto == 'M' || pto == 'A'){
		sources.pb({i, j}); 	 
	}
	if(pto == '#') return INF; 
	return 0; 
}

void read() {
	cin >> n >> m; pair<int, int> c;  
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char pto; cin >> pto; 		
			matrix[i][j] = {false, {pto, isSource(i, j, pto)}};
		}
	}
}

void fill_queue(queue<pair<int, int>>& q) {
	for(int i = 0; i < sources.size(); i++){
		q.push(sources[i]); 
		matrix[sources[i].f][sources[i].s].f = true; 	
	}
}

bool inside (pair<int, int> pt) {
	if(pt.f < 0 || pt.s < 0) return false; 
	if(pt.f >= n || pt.s >= m) return false; 
	return true; 
}
void add_adj(pair<int, int> pt, queue<pair<int, int>>& q, int val) {
	pair<int, int> right = {pt.f, pt.s + 1}; 	
	pair<int, int> left =  {pt.f, pt.s - 1}; 
	pair<int, int> up =    {pt.f - 1, pt.s}; 
	pair<int, int> down = {pt.f + 1, pt.s}; 	
	
	if(inside(right) && matrix[right.f][right.s].s.f != '#' && !matrix[right.f][right.s].f){
		if(matrix[right.f][right.s].s.f == 'M' || matrix[right.f][right.s].s.f == 'A') 
			 matrix[right.f][right.s].s.s = 0;   
		else 
			matrix[right.f][right.s].s.s = val + 1; 
		q.push(right); matrix[right.f][right.s].f = true; 	
	}
	
	if(inside(left) && matrix[left.f][left.s].s.f != '#' && !matrix[left.f][left.s].f){ 
  		if(matrix[left.f][left.s].s.f == 'M' || matrix[left.f][left.s].s.f == 'A') 
			matrix[left.f][left.s].s.s = 0;
		else  
			matrix[left.f][left.s].s.s = val + 1; 
		q.push(left); matrix[left.f][left.s].f = true; 	
	}
	
	if(inside(up) && matrix[up.f][up.s].s.f != '#' && !matrix[up.f][up.s].f) {
		if(matrix[up.f][up.s].s.f == 'M' || matrix[up.f][up.s].s.f == 'A') 
			matrix[up.f][up.s].s.s = 0; 
		else	
			matrix[up.f][up.s].s.s = val + 1; 
		q.push(up); matrix[up.f][up.s].f = true; 	
	}
	
	if(inside(down) && matrix[down.f][down.s].s.f != '#' && !matrix[down.f][down.s].f) {
		if(matrix[down.f][down.s].s.f == 'M' || matrix[down.f][down.s].s.f == 'A') 	
			matrix[down.f][down.s].s.s = 0; 
		else
			matrix[down.f][down.s].s.s = val + 1; 
		q.push(down);matrix[down.f][down.s].f = true; 	
	}
}

void debug() {
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) {
			cout << matrix[i][j].s.s << "\t"; 
		}
		cout << '\n';
	}	
}

void pos_sol(pair<int, int> pt) {
	int isPos = false; 
	if(pt.f == 0 || pt.s == 0 || pt.f == n-1 || pt.s == m-1) isPos = true; 
 	if(isPos && matrix[pt.f][pt.s].s.s != MAX) solutions.pb(pt);
}

pair<char, pair<int, int>> findNext(pair<int, int> pt, int val) {
	pair<int, int> right = {pt.f, pt.s + 1}; 	
	pair<int, int> left =  {pt.f, pt.s - 1}; 
	pair<int, int> up =    {pt.f - 1, pt.s}; 
	pair<int, int> down = {pt.f + 1, pt.s}; 		

	pair<char, pair<int, int>> response; int c = 0; 
	
	if(inside(right) && matrix[right.f][right.s].s.s == val - 1) {response = {'L', right}; c++;} 
	if(inside(left) && matrix[left.f][left.s].s.s == val - 1) {response = {'R', left}; c++;} 
	if(inside(up) && matrix[up.f][up.s].s.s == val - 1) {response = {'D', up}; c++;} 
	if(inside(down) && matrix[down.f][down.s].s.s == val - 1) {response = {'U', down}; c++;}
	
	if(c == 1) return response;
	return {'!', {-1, -1}};  
}

void printPath(stack<char> &path) {
	cout << "YES\n"; cout << path.size() << '\n'; 
	while(!path.empty()) {
		cout << path.top(); path.pop();
	}
	cout << '\n';
}

void answer() {
	if(!solutions.size()) {cout << "NO\n"; return;} 
	stack<char> path; char control; 
	for(int i = 0; i < solutions.size(); i++) {
		bool stop = false; 
		pair<int, int> pt = solutions[i];
		int val = matrix[pt.f][pt.s].s.s;
		
		if(matrix[pt.f][pt.s].s.f == 'A') 
				{stop = true; control = '!';} 
			
		auto it = findNext(pt, val);	
		control = it.f; pt = it.s;  
		val = matrix[pt.f][pt.s].s.s;	
				
		while(control != '!') {
			path.push(control);
				//cout << pt.f << " " << pt.s << '\n';	
			if(matrix[pt.f][pt.s].s.f == 'A') 
				{stop = true; control = '!';} 	
			else{
				auto it = findNext(pt, val);	
				control = it.f; pt = it.s;
				val = matrix[pt.f][pt.s].s.s; 	
			}	
		}	
		if(stop) {printPath(path); return;}
		while(!path.empty()) path.pop();
	}
	cout << "NO\n"; 
}

void solve() {
	queue<pair<int, int>> q;
	fill_queue(q); 
	while(!q.empty()) {
		pair<int, int> next_pt = q.front(); q.pop();	
		pos_sol(next_pt); // está na borda da matriz e não é uma parede? então venha para o vetor possíveis soluções.	
		add_adj(next_pt, q, matrix[next_pt.f][next_pt.s].s.s); 
	}
}


int main() {
	fastio;
	read();	
	solve();
	answer();
	//debug(); 
	return 0;
}


