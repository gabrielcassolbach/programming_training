#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<vector<int>> tree; 
vector<int> te, ts, h, func, ft; 

int t = 0;

void dfs(int node, int height){
	h[node] = height;
	te[node] = t++; 
	for(auto u : tree[node])
		if(te[u] == -1)
			dfs(u, height + 1);	
	ts[node] = t;
}

bool comp(int f1, int f2){
	return h[f1] > h[f2];
}

int query(int t_ent, int t_said){
	int sum = 0;
	for(int i = t_said; i > 0; i -= (i & -i)) sum += ft[i];
	for(int i = t_ent; i > 0; i -= (i & -i)) sum -= ft[i];
	return sum;
}

void update(int t_ent, int val){
	for(int i = t_ent+1; i <= n; i += (i & -i)) ft[i] += val;
}

int solve(){
	vector<int> v; 
	sort(func.begin(), func.end(), comp);
	int ans = 0;
	for(int i = 0; i < func.size(); i++){
		if(query(te[func[i]], ts[func[i]]) == 0)
			ans++, update(te[func[i]], 1), v.push_back(te[func[i]]);
	}
	for(int i = 0; i < v.size(); i++) 
		update(v[i], -1);
	return ans; 
}

int main(){
	ios_base::sync_with_stdio(0);
	cin >> n >> q; 
	tree.resize(n);
	for(int i = 1; i < n; i++){
		int val; cin >> val;
		tree[val-1].push_back(i);
	}
	te.resize(n, -1); ts.resize(n, -1);  h.resize(n);
	dfs(0, 0);
	
	ft.resize(n + 1, 0);
	while(q--){
		int val; cin >> val;
		func.resize(val);
		for(int i = 0; i < val; i++)
			cin >> func[i], func[i]--;
		cout << solve() << '\n';
	}

	return 0;
}
