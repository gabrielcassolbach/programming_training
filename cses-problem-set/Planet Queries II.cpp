#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define MAX 212345
#define MAX2 31


int n, q; 
vector<vector<int>> adj, rev_adj; 
vector<int> node_type, dist, color, tree_entry_point; 
int jump[MAX][MAX2];

void set_memo(){
    cin >> n >> q;
    adj.resize(n+1); rev_adj.resize(n+1);
    
    for(int i = 1; i <= n; i++){
        int val; cin >> val;
        adj[i].push_back(val);
        rev_adj[val].push_back(i);
    }
    
    node_type.resize(n + 1, -1);
    dist.resize(n + 1, 0);
    color.resize(n + 1, 0);

    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX2; j++)
            jump[i][j] = -1;
}

 
int best_pow(int x){
    int i = 0; 
    while((1 << i) <= x) i++;
    --i;
    return i; 
}
 
int binary_lifting(int x, int k){ 
    if((1 << k) == 1)  jump[x][k] = adj[x][0];
    if(jump[x][k] == -1) jump[x][k] = binary_lifting(binary_lifting(x, k-1), k-1);
    return jump[x][k];
}

void dfs(int node){
    color[node] = 1;
    
    for(int u : adj[node]){
    
        if(color[u] == 0)
            dfs(u);

        if(color[u] == 1){
            int pn = u, d = 0;

            do {
                node_type[pn] = u;
                dist[pn] = d++;
                pn = adj[pn][0];
            } while(pn != u);

            dist[u] = d;
        }
    }

    color[node] = 2;
}

void tree_dist(int node, int d){
    dist[node] = d; color[node] = 1;

    for(int u : rev_adj[node])
        if(!color[u])    
            tree_dist(u, d+1);

    color[node] = 2;
}

int in_cycle(int a, int b){
    if(a == b) return 0;
    if(adj[a][0] == b) return 1; 
    return (dist[b] - dist[a] + dist[node_type[a]]) % dist[node_type[a]]; 
}

int binary_jumps(int k, int a){     
    while(k > 0){   
        int bp = best_pow(k);
        a = jump[a][bp];
        k -= (1 << bp);
    }

    return a;
}

int main() {
    fastio;  
    set_memo();

    for(int i = 1; i <= n; i++)
        if(color[i] == 0)
            dfs(i);

    for(int i = 1; i <= n; i++)
        if(node_type[i] == -1)
            binary_lifting(i, 30);    
 
    color.assign(n+1, 0);
    for(int i = 1; i <= n; i++){
        if(node_type[i] != -1 && rev_adj[i].size() > 1){
            for(int u : rev_adj[i])
                if(node_type[u] == -1)
                    tree_dist(u, 1);
        }
    }
    
    while(q--){
        int a, b; cin >> a >> b;
        if(node_type[a] == node_type[b] && node_type[a] != -1)
            cout << in_cycle(a, b) << "\n";

        else if(node_type[a] == -1 && node_type[b] != -1){
            int j_node = binary_jumps(dist[a] - 0, a);
            if(node_type[j_node] == node_type[b]) 
                cout << in_cycle(j_node, b) + dist[a] - 0 << "\n";
            else
                cout << -1 << "\n";
        }

        else if(node_type[a] == -1 && node_type[b] == -1 && dist[a] >= dist[b]){
            int j_node = binary_jumps(dist[a] - dist[b], a);
            if(j_node == b) cout << dist[a] - dist[b] << "\n";
            else cout << -1 << "\n";
        }else
            cout << -1 << "\n";

    }


    return 0;
}




