#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

ll n, x; 
vector<ll> v;

void read(){
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        ll value; cin >> value;
        v.push_back(value);
    }
}

int main(){
    ll ans = 0;
    read();
    sort(v.begin(), v.end());
    int i = 0; int j = n-1;
    while(i <= j){
        if(i == j) 
            {j--; i++; ans++;}
        else if(v[i] + v[j] <= x)
            {j--; i++; ans++;}
        else 
            {j--; ans++;}
    }
    cout << ans << endl;
    return 0;
}
