#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;

vector<ll> values; // os pesos dos nós;
vector<vector<ll>> graph; // forma o grafo.
ll n;

void read(){
    cin >> n; 
    values.resize(n + 10); 
    graph.resize(n + 10);
    for(int i = 2; i <= n; i++){
        ll vertex; cin >> vertex; 
        graph[vertex].push_back(i); 
        graph[i].push_back(vertex); 
    }
    for(int i = 1; i <= n; i++) 
        {cin >> values[i];}
}

int main(){
    read();


    return 0;
}
