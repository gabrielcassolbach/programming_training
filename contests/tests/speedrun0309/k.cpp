#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool comp(pair<ll, int> p1, pair<ll, int> p2){
    return p1.first < p2.first;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t; 

    while(t--){
        vector<pair<ll, int>> v(4);
        for(int i = 0; i < 4; i++){
            cin >> v[i].first;
            v[i].second = (i < 2) ? 0 : 1; 
        }
    
        sort(v.begin(), v.end(), comp);

        if(v[0].second == v[1].second)
            cout << 0 << "\n";
        else
            cout << (v[2].first - v[1].first) << "\n";
    }



    return 0;
}