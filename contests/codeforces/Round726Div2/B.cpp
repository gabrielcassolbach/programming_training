#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;


void answer(ll n, ll m, ll i, ll j){
    // x = (1, 1);  y = (1, m); z = (n, 1); g = (n, m).
    // dist = 
    ll x, y;
    if(i > n-i)
    {
        if(j > m-j)
        {
            // primeiro
            x = 1;
            y = 1;
        }
        else
        {
            //segundo
            x = 1;
            y = m;
        }
    }
    else
    {
        if(j > m-j)
        {
            // terceiro
            x = n;
            y = 1;
        }
        else
        {
            // quarto
            x = n;
            y = m;
        }
    }
    cout << x << ' ' << y << ' ';
    if(x > n-x)
    {
        if(y > m-y)
        {
            // primeiro
            cout << 1 << ' ' << 1 << endl;
        }
        else
        {
            //segundo
            cout << 1 << ' ' << m << endl;
        }
    }
    else
    {
        if(y > m-y)
        {
            // terceiro
            cout << n << ' ' << 1 << endl;
        }
        else
        {
            // quarto
            cout << n << ' ' << m << endl;
        }
    }

    
}

int main(){
    int t; cin >> t;
    while(t--){
        ll n, m, i, j;
        cin >> n >> m >> i >> j;
        answer(n, m, i, j);
    }
    return 0;
}