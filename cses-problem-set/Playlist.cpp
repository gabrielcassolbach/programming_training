// Playlist.
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

int main(){
    int n; cin >> n;
    vector<ll> v; v.resize(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    for(int i = 1; i < v.size(); i++){
        if(v[i] == v[0])
            {v.erase(v.begin()); i--;}
    }
    
    int ans = -1;

    multiset<int> s; s.insert(v[0]);
    for(int i = 1; i < v.size(); i++){
        s.insert(v[i]);

        if(s.count(v[i]) > 1){
            cout << "in here" << endl;
            s.clear();
            s.insert(v[i-1]);
            s.insert(v[i]);
        }
        
        if((int) s.size() > ans)
            ans = s.size();
    }

    cout << ans << endl;

    return 0;
}
