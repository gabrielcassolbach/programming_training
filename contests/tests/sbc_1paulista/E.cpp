#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

struct product {
    bool available; 
    ll pos;
    ll val;
};

ll n, d;
vector<product> v;

bool comp(product p1, product p2){
    return p1.pos < p2.pos; 
}

void read(){
    cin >> n >> d; 
    v.resize(n); 
    for(int i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        v[i] = {true, a, b};
    }
    sort(v.begin(), v.end(), comp);
}

ll two_pointers(pair<int, int> &sol){
    int i, j = 0;
    ll bestsum = 0, sum = v[i].val;
    for(i = 0; i < n; i++){
        while(j+1 < n && v[j+1].pos - v[i].pos <= d){
            sum += v[j+1].val;
            j++;
            cout << "i: " << i << '\n';
            cout <<  "j: " << j + 1 << '\n';
            cout << "sum: " << sum << '\n';
        }
        if(sum > bestsum){
            sol.first = i; sol.second = j;
            bestsum = sum;
        }
        sum -= v[i].val;
    }
    return bestsum;
}

int main(){
    fastio;
    read();
    
    pair<int, int> sol1, sol2;
    ll d_man1 = two_pointers(sol1);
    cout << "sum1: " << d_man1 << '\n';

    /*
    for(int i = sol1.first; i <= sol1.second; i++)
        {v[i].available = false;}

    cout << d_man1 + two_pointers(sol2) << '\n';
    */
    return 0;
}

