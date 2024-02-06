#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

int binarySearch(vector<pair<ll, ll>> &v, int n, int value, int index){
    int a, b, c;
    a = 0; b = n-1; c = 0;     
    while(a <= b){
        c = ((a + b)/2);
        if(value == v[c].first && c != index)
            {cout << v[c].second + 1 << ' '; return 1;}
        if(v[c].first < value)
            {a = c + 1;}
        else 
            {b = c - 1;}
    }
    return 0;
}

void answer(vector<pair<ll, ll>> &v, int n, int k){
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        if(v[i].first >= k) continue;
        int pos_ans = binarySearch(v, n, k - v[i].first, i);
        if(pos_ans) 
            {cout << v[i].second + 1 << endl; return;} 
    }
    cout << "IMPOSSIBLE" << endl;
}

void read(vector<pair<ll, ll>> &v, int n){
    v.resize(n);
    for(int i = 0; i < n; i++)
        {cin >> v[i].first; v[i].second = i;}
}

int main(){
    ll n, x; cin >> n >> x;
    vector<pair<ll, ll>> v; 
    read(v, n);
    answer(v, n, x);
    return 0;
}