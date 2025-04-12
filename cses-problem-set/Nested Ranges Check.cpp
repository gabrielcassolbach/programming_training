#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

struct Range {
    int idx; 
    int a; 
    int b; 
}; 

int n, x, y; 
vector<Range> v; 
vector<int> contains, contained; 

bool order(Range l, Range r){
    return l.a == r.a ? (l.b > r.b) : (l.a < r.a); 
}

void solve(){
    set<int> end_t;
    for(int i = n-1; i >= 0; i--){
        auto it = end_t.upper_bound(v[i].b);  
        if(it != end_t.begin())
            contains[v[i].idx] = 1;
        end_t.insert(v[i].b);     
    }
    end_t.clear();

    for(int i = 0; i < n; i++){
        auto it = end_t.lower_bound(v[i].b);
        if(it != end_t.end())
            contained[v[i].idx] = 1; 
        end_t.insert(v[i].b);
    }
}

int main() {
    fastio; 
    cin >> n;
    contains.resize(n, 0); contained.resize(n, 0); 
    for(int i = 0; i < n; i++){
        cin >> x >> y; 
        v.push_back({i, x, y}); 
    }
    sort(v.begin(), v.end(), order);
    solve();
    for(int i = 0; i < n; i++)
        cout << contains[i] << " ";
    cout << '\n';
    for(int i = 0; i < n; i++)
        cout << contained[i] << " ";
    cout << '\n';
    return 0; 
}