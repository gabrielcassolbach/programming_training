#include <bits/stdc++.h>
using namespace std;
 
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

int main(){
    int n; cin >> n; 
    vector<pair<ll, ll>> v; v.resize(2*n);
    
    for(int i = 0; i < (2*n); i++) {
        ll value; cin >> value;
        v[i].first = value;
        if(i % 2 == 0) 
            v[i].second = 1;
        else 
            v[i].second = -1;
    }
    
    sort(v.begin(), v.end(), [](auto &left, auto &right){
        return (left.first < right.first);
    });

    /*for(int i = 0; i < (2*n); i++)
        cout << v[i].first << ' ' << v[i].second << endl;*/ 

    ll ans = 0, best_ans = 0;
    for(int i = 0; i < (2*n); i++){
        ans += v[i].second;
        if(best_ans < ans)
            best_ans = ans;        
    }
    cout << best_ans << endl;
    return 0;
}
