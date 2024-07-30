#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool cmp(pair<int, int> &a, pair<int, int> &b){
    return (a.second < b.second);
}

int main(){
    int ans = 0; int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), cmp);  
    int i = 0, comp = -1;
    while(i < n){
        if(v[i].first >= comp){
            ans++; comp = v[i].second;
        }
        i++;
    }
    cout << ans << endl;
    return 0;
}