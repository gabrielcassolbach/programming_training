#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back

typedef long long ll;

struct point {
    ll dist; 
    int id;
};

ll w, h, n;
vector<point> borders; 

bool in_borders(ll a, ll b, ll c, ll d) {
    bool pt1 = (a == 0 || a == w) || (b == 0 || b == h); 
    bool pt2 = (c == 0 || c == w) || (d == 0 || d == h);
    return (pt1 && pt2);
}

void set_borders(ll x, ll y, int id) {
    if(y == 0) 
        {borders.pb({x, id}); return;}
    if(y == h)
        {borders.pb({w + h + (w - x), id}); return;}
    if(x == 0)
        {borders.pb({w + h + w + (h-y), id}); return;}
    if(x == w)
        {borders.pb({w + y, id}); return;}
}

void read() {
    cin >> w >> h; 
    cin >> n;
    for(int i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        ll c, d; cin >> c >> d;
        if(in_borders(a, b, c, d)){
            set_borders(a, b, i);
            set_borders(c, d, i);
        }
    }  
}

bool comp_dist(const point &a, const point& b){
    return a.dist < b.dist;
}

string solve() {
    sort(borders.begin(), borders.end(), comp_dist);

    stack<int> st;
    vector<bool> vis; vis.resize(n, false);

    for(int i = 0; i < borders.size(); ++i){
        int id = borders[i].id;
        if(!vis[id]){
            vis[id] = true;
            st.push(id);
        }else{
            if(st.empty() || st.top() != id)
                return "N";   
            st.pop();
        }
    }
    return st.empty() ? "Y" : "N";
}

int main() {
    fastio;
    read();
    cout << solve() << '\n';
    return 0;
}