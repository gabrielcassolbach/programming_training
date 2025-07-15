#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll, pair<int, int>> m;
vector<ll> v, id;
set<ll> s, range; 

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n; 
    v.resize(n); id.resize(n, 1);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(m.find(v[i]) != m.end()){
            m[v[i]] = {m[v[i]].first, i};
            range.insert(v[i]);
        }else{
            m[v[i]] = {i, -1};
        }
    }
    for(auto it = range.begin(); it != range.end(); it++){
        int begin = m[*(it)].second;
        int end = m[*(it)].first;

        for(int j = begin-1; j > end; j--)
            id[j] = 0;
    }
    
    for(int i = 0; i < n; i++){
        //cout << id[i] << " ";
        if(id[i]) s.insert(v[i]);
    }
    //cout << '\n';
    cout << s.size() << '\n';
    return 0; 
}