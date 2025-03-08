#include <bits/stdc++.h>
using namespace std;

int x = 0, m1 = 0, m2 = 0;

int main(){
    vector<int> v;
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        cin >> x >> m1 >> m2;
        v.push_back(x); v.push_back(m1); v.push_back(m2);
        sort(v.begin(), v.end());
        if(v[2] + v[1] >= 10)
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
        v.clear();
    }
    return 0;
}