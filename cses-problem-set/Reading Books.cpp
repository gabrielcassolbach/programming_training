#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); 

int main() {
    fastio;
    int n; cin >> n;
    vector<int> v; v.resize(n);
    ll sum = 0;
    for(int i = 0; i < n; i++)
        {cin >> v[i]; sum += v[i];}
    int max_val = *max_element(v.begin(), v.end());
    if(sum - max_val < max_val) cout << 2*max_val << '\n';
    else cout << sum << '\n';
    return 0;
}

