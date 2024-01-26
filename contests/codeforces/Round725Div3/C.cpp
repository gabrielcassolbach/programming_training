#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

int main()
{
    ll t, n, l ,r, cn,x, y, upper, lower;
    cin >> t;
    while (t--)
    {
        cin >> n >> l >> r;
        ll a[n + 1];
        cn = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a+n);
        for(int i = 0; i < n; i++)
        {
            x = l - a[i];
            y = r - a[i];

            lower = lower_bound(a+1+i, a+n, x) - a;
            upper = upper_bound(a+1+i, a+n, y) - a;
            
            cout << "x: " << x << " y: " << y << endl;
            cout << "lwer: " << lower << " upr: " << upper << endl << endl;

           cn += abs(upper - lower);
        }

        cout << cn << endl;
    }  
}