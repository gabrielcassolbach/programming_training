#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {
    fastio;
    int n, x; 
    cin >> n >> x; 
    vector<int> v; v.resize(n); 
    for(int i = 0; i < n; i++)
        cin >> v[i];

    ll sum = 0, ans = 0;

    for(int i = 0, j = 0; i < n; i++){
        while(sum < x && j < n) sum += v[j++];
        if(sum == x) ans++;
        sum -= v[i];
    }    
    cout << ans << '\n';
    return 0;
}