#include <bits/stdc++.h>

using namespace std;

/*

1) Grafo bipartido para representar vertices de linhas e vertices de colunas
2) Caminho Euleriano (Fleury)


stack St;
put start vertex in St;
until St is empty
  let V be the value at the top of St;
  if degree(V) = 0, then
    add V to the answer;
    remove V from the top of St;
  otherwise
    find any edge coming out of V;
    remove it from the graph;
    put the second end of this edge in St;

*/

vector<int> fleury(vector<vector<int>> &g, int v0) {
    stack<int> st; st.push(v0);
    vector<int> ans;

    while(!st.empty()) {
        auto top = st.top();
        
        if(g[top].size() == 0) {
            ans.push_back(top); st.pop();
        }
        else {
            auto node = g[top][0];
            st.push(node);
            g[node].erase(find(g[node].begin(), g[node].end(), top));
            g[top].erase(g[top].begin());
        }   
    }

    return ans;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    // bipartite graph
    vector<vector<int>> bipartite_graph;
    vector<vector<char>> g;

    int n, m; cin >> n >> m;
   
    bipartite_graph.resize(n+m, vector<int>());
    g.resize(n, vector<char>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    if(n == 1 || m == 1) {
        cout << "*\n";
        return 0;
    }
    int dry = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] == '.'){
                dry++;
                bipartite_graph[i].push_back(j+n);
                bipartite_graph[j+n].push_back(i); 
            } 
        }
    }

    for(int i = 0; i < (int) n; i++){
        for(int j = 0; i < (int) bipartite_graph[i].size(); i++){
            cout << bipartite_graph[i][j] << " ";
        }
        cout << "\n";
    }


    vector<int> path = fleury(bipartite_graph, 0);
    reverse(path.begin(), path.end());
    
    if((int) path.size() != dry+1) {
        cout << "*\n";
        return 0;
    }

    vector<vector<int>> ans;
    ans.resize(n, vector<int>(m));
    for(int i = 0; i < (int) path.size(); i++)
        cout << path[i] <<  " ";
    cout << "\n";
    int cont = 1;
    for(int i = 1; i < (int) path.size(); i++){
        int a = path[i-1], b =path[i];
        if(a >= n)
            a = path[i-1] - n;
        if(b >= n)
            b = path[i] - n;
        cout << a << " " << b << "\n";
        if(i % 2)
            ans[a][b] = cont++;
        else
            ans[b][a] = cont++;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(ans[i][j] > 0)
                cout << ans[i][j] << " ";
            else 
                cout << 0 << " ";
        }
        cout << "\n";
    }
}
