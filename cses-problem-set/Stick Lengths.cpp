/* Tentar encontrar a prova matemática para esse algoritmo, voltar nele!*/
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

ll answer(vector<ll> &v, int n, ll sum){
    ll ans3 = 0;
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++)
        ans3 += abs(v[i] - v[n/2]);
    return ans3;
}

int main(){
    int n; cin >> n;
    vector<ll> v; v.resize(n);
    ll sum = 0;
    for(int i = 0; i < n; i++)
        {cin >> v[i]; sum += v[i];}
    cout << answer(v, n, sum) << endl;
    return 0;
}
