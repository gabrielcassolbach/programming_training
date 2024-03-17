#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main(){
    int t; cin >> t;
    vector<int> v;
    while(t--){
        int n; cin >> n;
        v.resize(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        int i = 0; int j = n-1; int l = n-2; int k = 1;
        cout << (abs(v[i]-v[j]) + abs(v[j]-v[k]) + abs(v[k]-v[l]) + abs(v[l]-v[i])) << endl;
    }
    return 0;
}