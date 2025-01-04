#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 212345
#define INF 1123456789

typedef long long ll;

typedef struct {
	ll a;
	ll b;
	ll c;
} Project;

vector<Project> v;
ll dp[MAX];
int n;

bool aCompare(const Project& one, const Project& two) {
	return one.b < two.b;
}

void read() {
	cin >> n; v.resize(n); 
	for(int i = 0; i < n; i++)
		cin >> v[i].a >> v[i].b >> v[i].c;	
	sort(v.begin(), v.end(), aCompare);
}

int getNextPossible(int it) {
	int a = 0; int b = it - 1; int mid = 0;
	int has_sol = 0, choice = 0;
	ll x = v[it].a - 1;
	while(a <= b) {
		mid = (a + b)/2;
		if(v[mid].b == x) 
			return mid; 
		if(v[mid].b < x){
			a = mid + 1;
			has_sol = 1;
			choice = mid;	
		}else 
			b = mid - 1;
	}
	if(v[mid].b < x) return mid;
	if(!has_sol) return -INF;
	else return choice;
}

ll solve(int it) {
	if(it < 0) return 0;
	if(dp[it] != -1) return dp[it];
	int pos = getNextPossible(it); 
	dp[it] = max(solve(it - (it-pos)) + v[it].c, solve(it-1));	
	return dp[it];
}

int main() {
	fastio;
	read();
	memset(dp, -1, sizeof dp);
	cout << solve(n-1) << '\n';
	return 0;
}	

