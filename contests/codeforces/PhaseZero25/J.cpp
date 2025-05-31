#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define s second 
#define f first

typedef long ll;

ll n, k; 
vector<ll> v, ans;
vector<pair<ll, int>> aux_v; 

bool comp(pair<ll, int> &a1, pair<ll, int> &a2){
    return a1.f > a2.f; 
}

void read() {
    cin >> n >> k;  
    v.resize(n); aux_v.resize(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        aux_v[i] = {v[i], i};
    }
    sort(aux_v.begin(), aux_v.end(), comp);
}

int main() {
    fastio;
    read();
    ans.resize(n, -1);
    for(int i = 0; i < n; i++){
        int idx = aux_v[i].s;
        int x = (idx + 1)%n;
        ll sum = v[idx]+k;
        while(sum <= v[x]) {
            sum += k*((n+ans[x]-x)%n);
            x = ans[x];
        }
        ans[idx] = x;
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] + 1 << " ";
    cout << '\n';
    return 0; 
}