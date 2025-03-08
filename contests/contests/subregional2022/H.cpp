#include <bits/stdc++.h>
using namespace std;

#define _                             \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

typedef long long ll;

vector<vector<ll>> graph;
vector<ll> vis;
vector<ll> entra;
vector<ll> sai;
ll n, m;

void read()
{
    cin >> n >> m;
    graph.resize(n + 10);
    vis.resize(n + 10);
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
    }
}

void print_g (){
    for (int i = 0; i < n; i++) {
        cout << i+1 << ": ";
        for(int j = 0; j < graph[i].size(); j++){
            cout << graph[i][j]+1 << " ";
        }
        cout << endl;
    }
}

void dfs(ll node, ll entrada)
{
    //cout << node << endl;
    vis[node] = 1;
    for (auto it = graph[node].begin(); it != graph[node].end(); it++)
    {
        if (entrada != *it){
            entra[*it] = 1;  
            sai[node] = 1;  
        }
        if (!vis[*it])
        {
            dfs(*it, entrada);
        }
    }
}

void setVectors()
{
    entra.resize(n + 10);
    sai.resize(n + 10);
    for (int i = 0; i < n; i++){
        vis[i] = 0;
        entra[i] = 0;
        sai[i] = 0;
    }
}

ll ans() {
    ll sum1 = 0;
    for (int i = 0; i < n; i++){
        cout << entra[i] << " ";
        sum1 += entra[i];
    }
    cout << endl;
    ll sum2 = 0;
    for (int i = 0; i < n; i++) {
        cout << sai[i] << " ";
        sum2 += sai[i];
    }
    cout << endl;
    return max(n-sum1, n-sum2);
}


int main()
{
    _  read();
    setVectors();
    print_g();
    cout << endl << endl;
    for (int i = 0; i < n; i++)
        if (!vis[i])
            dfs(i, i);
    cout << ans() << endl;
    return 0;
}