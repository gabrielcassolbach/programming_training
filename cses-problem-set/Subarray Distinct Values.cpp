#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

vector<int> v; 
map<int, int> freq;
int n, k;

ll solve(){
    int j = 0; ll ans = 0; 
    for(int i = 0; i < v.size(); ++i){
        freq[v[i]]++;
        while(freq.size() > k){
            freq[v[j]]--;
            if(freq[v[j]] == 0) freq.erase(v[j]);
            j++;
        }
        ans += (i-j+1);
    } 
    return ans;
}

int main() {
    fastio; 
    cin >> n >> k; 
    v.resize(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    cout << solve() << '\n';
    return 0;
}