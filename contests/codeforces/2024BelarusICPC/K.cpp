#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define MAX 112345

typedef long long ll;

vector<int> val; 
vector<ll> p_sum;
int n, m; 

void set_data() {
    for(int i = 0; i < n; i++) 
         cin >> val[i];
        
    p_sum[0] = 0;
    for(int i = 1; i <= n; i++) 
        p_sum[i] = p_sum[i-1] + val[i-1];
}

ll solve(int sd, int sm, int ed, int em) {
    if(sm == em && sd <= ed) 
        return ed - sd + 1;

    if(em == sm && sd > ed) {
        swap(ed, sd);
        ll x = ed - sd + 1;
        return p_sum[n] - x + 2;
    }

    if(em < sm){
        swap(ed, sd); swap(em, sm);
        ll x = -sd + 1 + ed + p_sum[em] - p_sum[sm];   
        return p_sum[n] - x + 2;
    }

    return -sd + 1 + ed + p_sum[em] - p_sum[sm];   
}

int main() {
    fastio;
    int t; cin >> t;
    val.resize(MAX); p_sum.resize(MAX);
    while(t--){
        cin >> n >> m;
        set_data();
        while(m--){
            int sd, sm, ed, em;
            cin >> sd >> sm >> ed >> em; sd; sm--; ed; em--;
            cout << solve(sd, sm, ed, em) << '\n';
        }
    }
    return 0;
}