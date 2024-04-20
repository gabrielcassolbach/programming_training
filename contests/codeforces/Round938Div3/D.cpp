#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

int t, n, m, k;
map<int, int> mpa, mpb;
vector<ll> v1, v2;

void read(){
    cin >> n >> m >> k;
    mpa.clear(); mpb.clear();
    v1.resize(n + 1); v2.resize(m + 1);
    for(int i = 1; i <= n; i++)
        {cin >> v1[i];}
    for(int i = 1; i <= m; i++)
        {cin >> v2[i]; mpa[v2[i]]++;}
}

void answer(){
    int cnt = 0, ans = 0;
    for(int i = 1; i <= n; i++){
        cnt -= min(mpa[v1[i]], mpb[v1[i]]); 
        mpb[v1[i]]++;
        cnt += min(mpa[v1[i]], mpb[v1[i]]); 
        if(i > m){
            cnt -= min(mpa[v1[i-m]], mpb[v1[i-m]]); 
            mpb[v1[i-m]]--;
            cnt += min(mpa[v1[i-m]], mpb[v1[i-m]]); 
        }
        if(i >= m && cnt >= k)
            ans++;
    }
    cout << ans << endl;
    return;
}

int main(){
    cin >> t;
    while(t--){
        read();
        answer();
    }
    return 0;
}