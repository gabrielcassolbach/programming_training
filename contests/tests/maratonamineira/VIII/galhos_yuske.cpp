#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
map<int,int> time_fall;

void remove_balls(int i, int t){
    for(int j = 0; j < g[i].size(); j++){
        remove_balls(g[i][j], t);
    }
    if(!time_fall[i])
        time_fall[i] = t;
    g[i].clear();
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n; cin >> n;

    g.resize(n, vector<int>());
    for(int i = 0; i < n; i++){
        int p; cin >> p;
        if(p < 0)
            continue;
        g[i].push_back(p-1);
    }

    for(int i = 0; i < n; i++){
        int b; cin >> b;
        remove_balls(b-1, i+1);
    }

    for(int i = 0; i < n; i++){
        cout << time_fall[i] << " ";
    }

    cout << "\n";

    return 0;
}
