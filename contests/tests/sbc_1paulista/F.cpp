#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int>> g; 
vector<int> val; 
vector<int> vis; 

int k;

pair<int, int> bfs(int node) {
    vis[node] = 1;

    int cost = 0;

    int longest_branch = 0;
    for(auto neighbor : g[node]) {
        if(!vis[neighbor]){
            pair<int, int> new_cost = bfs(neighbor);
            if(longest_branch < new_cost.second)
                longest_branch = new_cost.second;
            cost += new_cost.first;
        }
    }
    //cout << "cost: " << cost << 
    if(cost == 0 && val[node] > k)
        return make_pair(1, 0);
    if(cost != 0)
        return make_pair(cost + 1, longest_branch + 1);
    return make_pair(cost, 0);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n; cin >> n >> k;
    g.resize(n + 1); 
    val.resize(n + 1); vis.resize(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    for(int i = 1; i <= n-1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    pair<int, int> values = bfs(1);
    int sum = values.first;
    sum = sum == 0 ? sum : sum - 1;
    int max_distance = values.second;
    // resp = 2 * soma das distancias - maior distancia
    cout << (2 * sum) - max_distance << "\n";
    return 0;
}