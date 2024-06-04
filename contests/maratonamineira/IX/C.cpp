#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

vector<ll> v; 
vector<ll> memo;
ll n; 

void read(){
    cin >> n;
    v.resize(n); memo.resize(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
}

void answer(){
    memo[0] = v[0]; 
    memo[1] = max(v[0], v[1]);
    for(int i = 2; i < n; i++)
        memo[i] = max(v[i] + memo[i-2], memo[i-1]);
    cout << memo[n-1] << endl;
}

int main(){
    read();
    answer();
    return 0;
}