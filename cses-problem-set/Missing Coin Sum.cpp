#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n; cin >> n;
    vector<ll> v; v.resize(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    sort(v.begin(), v.end());

    ll sum = v[0];
    if(sum != 1)
        {cout << 1 << endl; return 0;}

    for(int i = 1; i < n; i++){ 
        if(v[i] > sum + 1)
            {cout << sum + 1 << endl; return 0;}
        sum += v[i];
    }

    cout << sum + 1 << endl;
    return 0;
}