#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define MAX 212345
#define MAX2 31


int n, q; 
vector<vector<int>> adj, rev_adj; 
vector<int> node_type, dist, vis; // 0 is a node in a tree; 1 is a node in a cycle.
// 2 is a node in a different cycle and so on. 
int jump[MAX][MAX2];

void set_memo(){
    cin >> n >> q;
    adj.resize(n+1); rev_adj.resize(n+1);
    
    for(int i = 1; i <= n; i++){
        int val; cin >> val;
        adj[i].push_back(val);
        rev_adj[val].push_back(i);
    }
    
    node_type.resize(n + 1, 0);
    dist.resize(n + 1, 0);
    vis.resize(n + 1, 0);


    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX2; j++)
            jump[i][j] = -1;
}

void find_cycles_dfs(int node){
    vis[node] = 1;

    for(int u : adj[node]){
        if(vis[u] == 0)
            find_cycles_dfs(u);
        
        if(vis[u] == 1) 
            node_type[u] = 1;       
    }

    vis[node] = 2;
}

void mark_cycles_dfs(int node, vector<int> &cycle_ep, int cycle_counter){
    vis[node] = 1;
    node_type[node] = cycle_counter;
   
    if(rev_adj[node].size() > 1) cycle_ep.push_back(node);
    
    for(int u : adj[node])
        if(!vis[u])
            mark_cycles_dfs(u, cycle_ep, cycle_counter);
}

void set_dist_dfs(int node, int d){
    //cout << "node: " << node << " " << d << "\n";
    vis[node] = 1; 
    if(!dist[node]) dist[node] = d;
    
    for(int u : rev_adj[node]){
        if(!vis[u])
            set_dist_dfs(u, d+1);
    }
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


int main() {
    fastio;  
    set_memo();

    for(int i = 1; i <= n; i++)
        if(!vis[i])
            find_cycles_dfs(i);

    vis.assign(n+1, 0);
    
    vector<int> cycle_ep;
    int cycle_counter = 1;
    for(int i = 1; i <= n; i++)
        if(node_type[i] == 1 && !vis[i])
            mark_cycles_dfs(i, cycle_ep, cycle_counter++);
            

    vis.assign(n+1, 0);
    if(cycle_ep.size() == 0) cycle_ep.push_back(1);
    for(int i = 0; i < (int) cycle_ep.size(); i++)
        set_dist_dfs(cycle_ep[i], 0);

    for(int i = 1; i <= n; i++)
        if(node_type[i] == 0)
            binary_lifting(i, 30);    

    while(q--){
        int a, b; cin >> a >> b;
      
        //cout << node_type[a] << " " << node_type[b] << "\n";
        cout << "aqui: " << dist[a] << " " << dist[b] << "\n";
        if(node_type[a] == node_type[b] && node_type[a] != 0) // inside a cycle
            cout << abs(dist[a] - dist[b]) << "\n";
        
        else if(node_type[a] != node_type[b] && node_type[a] && node_type[b]) // different cycles.
            cout << -1 << "\n";
        
        else if(node_type[a] == node_type[b] && node_type[a] == 0) {
           
            if(dist[a] >= dist[b]){
                int k = dist[a] - dist[b];
                int dist_ = k;

                while(k > 0){
                    int bp = best_pow(k);
                    a = jump[a][bp];
                    k -= (1 << bp);
                }     

                if(a == b)
                    cout << dist_ << "\n";
                else
                    cout << -1 << "\n";

            } else { 
                cout << -1 << "\n"; 
            } 
            
        }else  { // in a tree and in a cycle
    
            if(node_type[a] != 0 && node_type[b] == 0)
                cout << -1 << "\n";
            else{
                // climb node in a tree to a cycle
                int k = dist[a] - 0; int dist_ = k;
                
                while(k > 0){
                    int bp = best_pow(k);
                    a = jump[a][bp];
                    k -= (1 << bp);
                }
                
                if(node_type[a] != node_type[b])
                    cout << -1 << "\n";
                else
                    cout << dist_ + abs(dist[a] - dist[b]) << "\n";

            }   
        }


    }



    return 0;
}




