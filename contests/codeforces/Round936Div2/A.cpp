#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

vector<ll> v;
ll n;

void read(){
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
}

int main(){
    int t; cin >> t;
    while(t--){
        ll ans = 0;
        read();
        sort(v.begin(), v.end());
        int index = (ceil((n-1)/2));
        v[index]++;
        ans++;
        for(int i = index + 1; i < n; i++){
            while(v[i] < v[index])
                {v[i]++; ans++;}
        }
        cout << ans << endl;
    }
    return 0;
}