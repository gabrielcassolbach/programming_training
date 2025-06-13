#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

struct store {
    ll x;
    ll v;
};

ll n, d;
vector<store> v; 
vector<int> vis; 

ll rec(int it, int pos_lc) {
    if(it == n) return 0;
    cout << "it: " << it << '\n';
    bool canpick = pos_lc == -1 ? true : (v[it].x - pos_lc <= d);

    ll choice1 = canpick ? rec(it + 1, v[it].x) + v[it].v : 0;
    ll choice2 = rec(it + 1, pos_lc);

    if(choice1 > choice2)
        {return choice1;}
    else
        {return choice2;}
}

int main(){
    fastio;
    cin >> n >> d; 
    v.resize(n); vis.resize(n, 0);

    for(int i = 0; i < n; i++){
        ll xi, vi; cin >> xi >> vi;
        v[i] = {xi, vi};
    }

    cout << rec(0, -1) << '\n';
    for(int i = 0; i < n; i++) cout << vis[i] << ' ';
    cout << '\n';
    return 0;
}

