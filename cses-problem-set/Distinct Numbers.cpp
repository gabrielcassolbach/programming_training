#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 212345

typedef long long ll;

int main(){
    ll ans = 1;
    ll n, values[MAX];
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> values[i];
    sort(values, values + n);
    for(int i = 1; i < n; i++)
        if(values[i] != values[i-1])
            ans++;
    cout << ans << endl;
    return 0;  
}