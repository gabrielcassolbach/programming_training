#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        ll n, k, tmp, f, l;
        cin >> n >> k;
        f = 0;
        l = n-1; 
        vector<ll> a;
        for (ll j = 0; j < n; j++)
        {
            cin >> tmp;
            a.push_back(tmp);
        }   
        int val; int af_ant, al_ant;
        while (k > 0) {
            val = min(a[f], a[l]);
            af_ant = a[f]; al_ant = a[l];
            a[f] -= val;
            a[l] -= val;
            if (!a[f]) f++;
            if (!a[l]) l--;
            k -= 2*val;
        }
        int cont = 0;
        if(k == 0)  cout << n-(l-f+1) << endl;
        else {
            ll subf = ceil((k + 2*val)/2.0);
            ll subl = (k + 2*val)/2;
            int x = (af_ant - subf) <= 0;
            int y = (al_ant - subl) <= 0;
            cout << n-(l-f+1) - x - y;
        }   
    }
    
    return 0;
}