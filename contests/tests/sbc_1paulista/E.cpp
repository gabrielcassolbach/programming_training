#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

struct product {
    int pos; 
    int val;
};

bool comp(product p1, product p2){
    return p1.pos < p2.pos;
}

int main(){
    fastio; 
    int n, d; 
    cin >> n >> d;

    vector<product> v;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;    
        v.push_back({a, b});
    }

    sort(v.begin(), v.end(), comp);
    for(int i = 0; i < v.size(); i++) cout << v[i].pos << " ";
    vector<int> sums; 

    int i, j = 1;
    int sum = v[0].val;
    for(i = 0; i < n; i++){
        while(j < n && v[j].pos - v[i].pos <= d){
            sum += v[j++].val;   
        }
        sums.push_back(sum);
        sum -= v[i].val;
    }

    sort(sums.begin(), sums.end(), greater<int>());
    for(int i = 0; i < sums.size(); i++) cout << sums[i] << " ";

    if(sums.size() > 1)
        cout << sums[0] + sums[1] << '\n';
    else 
        cout << sums[0] << '\n';
    return 0;
}