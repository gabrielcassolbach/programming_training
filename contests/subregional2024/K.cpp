#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 112
#define MAX2 11234

typedef long long ll;

ll n; vector<pair<ll, ll>> v; 
ll dp[MAX][MAX2];
vector<ll> sol, res; 

void read(){
    cin >> n; v.resize(n + 10);
    for(int i = 0; i < n; i++)
        {cin >> v[i].first; v[i].second = 0;}
}

void init(){
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX2; j++)
            dp[i][j] = -1;
}

ll getSum(){
    ll sum = 0;
    for(int i = 0; i < n; i++)
        sum += v[i].first;
    return sum;
}

void getSubset(ll i, ll j){
    if(i == 0 || j == 0) return;
    if(dp[i-1][j] == dp[i][j])
        getSubset(i-1, j);
    else
        {v[i].second = 1; getSubset(i-1, j - v[i].first);} 
}

ll bag(ll index, ll weight){
    if(!index || !weight) 
        return dp[index][weight] = 0;
    if(dp[index][weight] != -1)
        return dp[index][weight];
    if(v[index].first > weight)
        dp[index][weight] = bag(index-1, weight);
    else 
        dp[index][weight] = max(bag(index-1, weight), bag(index-1, weight-v[index].first) + v[index].first);
    return dp[index][weight];
}

void answer(){
    for(int i = 0; i < n; i++) {
        if(v[i].second) sol.push_back(v[i].first);
        else res.push_back(v[i].first);
    }
    int i, j; i = j = 0; ll sum_a, sum_b; 
    sum_a = sum_b = 0;
    cout << sol[i] << " "; sum_a += sol[i]; i++;
    while(i != sol.size() || j != res.size()){
        if(sum_a <= sum_b) {
            cout << sol[i] << " ";
            sum_a += sol[i]; i++;
        }else{
            cout << res[j] << " ";
            sum_b += res[j]; j++;
        }
    }
    cout << "\n";
}

int main(){ _
    read();
    init();
    ll sum = getSum();
    if(sum % 2) 
        {cout << -1 << '\n'; return 0;}
   
    bag(n-1, sum/2);
    if(dp[n-1][sum/2] != sum/2) {cout << -1 << "\n"; return 0;}
    getSubset(n-1, sum/2);
    answer();
    return 0;
}