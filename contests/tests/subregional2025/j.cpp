#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<int> v; v.resize(5, 0);
    for(int i = 1; i <= 10; i++){
        int a; cin >> a;
        v[a]++;
    }
    int ans = 0;
    for(int i = 1; i <= 4; i++)
        {if(!v[i]) ans++;}
    cout << ans << "\n";
    return 0;
}