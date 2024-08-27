#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;

int main() { _
    ll n, k, l; cin >> n; 
    vector<ll> cima, baixo; 
    cima.resize(n + 10); baixo.resize(n + 10);
    for(int i = 0; i < n; i++) cin >> cima[i];
    for(int i = 0; i < n; i++) cin >> baixo[i];
    cin >> k >> l;

    ll ans = 0; 
    multiset<ll> s;

    ll tmp_ans = 0; 
    for(int i = n-k; i < n; i++){
        tmp_ans += cima[i];
        s.insert(baixo[i]);
    }
    auto it = --s.end();
    for(int i = 0; i < l; i++){
        tmp_ans += (*it);
        --it;
    }

    /*
      5
9 7 2 2 9
5 9 2 3 1

    14
    23
    25
    18
    7
    */
    ans = max(tmp_ans, ans);
    auto it2 = s.begin(); int baixo_int = 0;

    for(int i = 0; i < n-1; i++){   
        tmp_ans += (cima[i] - cima[(n-k+i) % n]);
     
        auto it = s.find(baixo[(n-k+i) % n]); 
        auto it_aux = it;
        while(*(++it_aux) == (*it) && it != --s.end()) ++it;
 
        int d = distance(s.begin(), it);         
        if(d >= s.size() - l ) tmp_ans -= (*it);  

        s.erase(it); s.insert(baixo[i]);
       
        if(distance(s.begin(), it2) < s.size() - l && baixo_int) tmp_ans -= (*it2);
        
        it2 = s.find(baixo[i]);
        d = distance(s.begin(), it2);
        if(d >= s.size() - l ) {
            baixo_int = 1;
            tmp_ans += (*it2);
        }else{
            baixo_int = 0;
        }
      
        ans = max(tmp_ans, ans);
    }

    cout << ans << endl;

    return 0;
}