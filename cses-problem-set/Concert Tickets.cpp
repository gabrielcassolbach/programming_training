/*
This solution was based in the code: 
https://github.com/berarchegas/CSES-Solutions/blob/master/src/1091%20-%20Concert%20Tickets.cpp
*/

#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

multiset<ll> v; 
ll n, m; 

void read(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        ll val; cin >> val;
        v.insert(-val);
    } 
}

void answer(){
    ll aux;
    for(int i = 0; i < m; i++){
        cin >> aux;
        auto it = v.lower_bound(-aux);
        if(it == v.end())
            cout << -1 << endl;
        else{
            cout << -(*it) << endl;
            v.erase(it);
        }
    }
}

int main(){
    read();
    answer();
    return 0;
}

