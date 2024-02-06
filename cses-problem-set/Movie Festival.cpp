/* -> Problema da Seleção de Atividades <- */
#include <bits/stdc++.h>
using namespace std;
 
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

int main(){
    int n; cin >> n;
    multiset<pair<ll, ll>> v;
    
    for(int i = 0; i < n; i++){
        ll ti, tf; cin >> ti >> tf;
        v.insert(pair(tf, ti));
    }

    int ans = 0;
    int lepnt = 0; // last ending point.
    for(auto it = v.begin(); it != v.end(); ++it){
        //cout << (*it).second << ' ' << lepnt << endl;
        if((*it).second >= lepnt)
            {ans++; lepnt = (*it).first;} 
    }
    cout << ans << endl;
    return 0;
}