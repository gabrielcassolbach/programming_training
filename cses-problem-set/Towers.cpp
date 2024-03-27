#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

int main(){
    multiset<ll> s;
    int n; ll val;
    cin >> n; cin >> val; 
    s.insert(val);
    for(int i = 1; i < n; i++){
        cin >> val; 
        s.insert(val);
        auto it = s.upper_bound(val);
        if(it != s.end())
            s.erase(it);
    }
    cout << s.size() << endl;
    return 0;
}