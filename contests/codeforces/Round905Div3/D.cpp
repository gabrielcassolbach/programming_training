// Solução feita por @joaoreis28.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


multiset<pair<ll,ll>> lr, rl;


 
int main(){
       
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;


    char c;
    ll l, r;

    for (int i = 0; i < t; i++){
        cin >> c >> l >> r;

    if(c == '+')
    {
        lr.insert({l ,r});
        rl.insert({r ,l});
    }
    else
    {
        lr.erase(lr.find({l, r}));
        rl.erase(rl.find({r,l}));
    }


    if(lr.size() <= 1)
        cout << "NO" << endl;

    else
    {
        auto i = rl.begin();
        auto e = lr.end();
        e--;

        if( (*i).first < (*e).first)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    }
  
    return 0;
}
