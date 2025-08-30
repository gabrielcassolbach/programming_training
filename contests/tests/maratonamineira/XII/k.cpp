#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n; cin >> n; 
    vector<pair<int, int>> v(n);
    
    for(int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    cout << n << "\n";
    int t = 0;
    for(int i = 0; i < n; i++){
        cout << v[i].first + v[i].second*t << " " << t << "\n";
        t++;
    }   
    

    return 0; 
}