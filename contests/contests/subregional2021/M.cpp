#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;

vector<ll> finished;
vector<ll> vivo;
vector<ll> pai;
vector<set<ll>> graph; 
ll n; ll id = 2; ll rei = 1;

ll find_rei(ll pessoa){
    if(finished[pessoa]) return 0;
    if(vivo[pessoa]) return pessoa;
    for(auto u : graph[pessoa]){

        ll new_rei = find_rei(u);
        if(new_rei != 0) return new_rei; 
    }

    finished[pessoa] = 1;
    graph[pai[pessoa]].erase(pessoa); 

    ll new_rei = find_rei(pai[pessoa]);
    if(new_rei != 0) return new_rei; 

    return 0;
}

int main(){ _
    cin >> n; 
    graph.resize(n + 10); pai.resize(n+10); vivo.resize(n+10, 1);
    finished.resize(n + 10, 0);
    while(n--){
        ll t, x; cin >> t >> x; // 1 1
        if(t == 1) {
            graph[x].insert(id);
            pai[id] = x;
            id++;
        }else { 
            vivo[x] = 0;
            if(x == rei){
                rei = find_rei(x);
            }
            cout << rei << endl;
        }
    }
    return 0;
}