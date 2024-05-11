#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        ll n, xi;
        vector<ll> x;
        cin >> n;
        for (ll j = 0; j < n-1; j++)
        {
            cin >> xi;
            x.push_back(xi);
        }

        vector<ll> a;
        a.resize(n);
        a[n-1] = 100000000;
        for (ll j = n-2; j >= 0; j--)
        {
            a[j] = a[j+1] - x[j];
        }
        
        for (ll j = 0; j < n; j++)
        {
            cout << a[j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}