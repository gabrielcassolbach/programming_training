#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);

    ll w, h;
    int n;
    cin >> w >> h;
    cin >> n;

    vector<pair<ll,int>> valid_pairs;

    auto boundary_pos = [&](ll x, ll y) -> ll { // no sentido horário
        if(y == 0 && x >= 0 && x <= w)
            return x; // topo
        else if(x == w && y >= 0 && y <= h)
            return w + y; // direita
        else if(y == h && x >= 0 && x <= w)
            return w + h + (w - x); // baixo
        else if(x == 0 && y >= 0 && y <= h)
            return w + h + w + (h - y); // esquerda
        else
            return -1; // fora
    };

    for(int i = 0; i < n; i++){
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll p1 = boundary_pos(x1, y1);
        ll p2 = boundary_pos(x2, y2);
        if(p1 >= 0 && p2 >= 0){
            valid_pairs.push_back({p1, i});
            valid_pairs.push_back({p2, i});
        }
    }

    // Não tem pares nas bordas
    if(valid_pairs.empty()){
        cout << "Y\n";
        return 0;
    }

    sort(valid_pairs.begin(), valid_pairs.end(), [](pair<ll,int> &a, pair<ll,int> &b) {return a.first < b.first;});

    vector<bool> seen(n, false);
    stack<int> pair_stack;

    for(auto &pair : valid_pairs){
        int id = pair.second;
        if(!seen[id]){
            seen[id] = true;
            pair_stack.push(id);
        } 
        else{
            if(pair_stack.empty() || pair_stack.top() != id){
                cout << "N\n";
                return 0;
            }
            pair_stack.pop();
        }
    }

    cout << (pair_stack.empty() ? 'Y' : 'N') << "\n";
    return 0;
}