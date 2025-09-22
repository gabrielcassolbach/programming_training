#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll n, l; cin >> n >> l;
    
    vector<ll> pos, neg;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        ll val; cin >> val; 
        if(val > 0)
            pos.push_back(val);
        else 
            neg.push_back(val);
        sum += val;
    }

    ll lower = -l, upper = l-1;
    if(sum > upper || sum < lower) 
        {cout << "N\n"; return 0;}
    
    cout << "S\n";
    int i = 0, j = 0;
    sum = 0; vector<ll> ans; 
    while(i < (int) pos.size() && j < (int) neg.size()){
        if(sum < 0) 
            {sum += pos[i]; ans.push_back(pos[i++]);}
        else 
            {sum += neg[j]; ans.push_back(neg[j++]);}
    }

    while(i < (int) pos.size())
        ans.push_back(pos[i++]);
    
    while(j < (int) neg.size())
        ans.push_back(neg[j++]);

    for(int i = 0; i < (int) ans.size(); i++)
        cout << ans[i] << (i == (int) ans.size() - 1 ? "\n" : " ");


    return 0;
}