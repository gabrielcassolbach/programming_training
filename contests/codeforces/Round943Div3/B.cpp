#include <iostream>

typedef long long ll;

using namespace std;

int main() {
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        ll n, m;
        string a, b;
        cin >> n >> m;
        cin >> a;
        cin >> b;

        ll max = 0;
        for (ll j = 0, k = 0; j < m; j++)
        {
            if (b[j] == a[k])
            {
                max++;
                k++;
            }
        }
        cout << max << endl;
    }
    
    return 0;
}