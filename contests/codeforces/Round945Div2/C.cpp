#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        ll n, x;
        vector<ll> p, q;
        cin >> n;
        // Escohe posições para máximos (sem 1)
        int impares = 1;
        for (ll j = 0; j < n; j++)
        {
            cin >> x;
            if (x == 1 && j%2==1) {
                impares = 0;
            }
            p.push_back(x);
        }
        q.resize(n);

        // Nas posições de máximos adiciona os maiores valores (q) nas posicoes com os menores valores(p)
        list<pair<ll, ll> > max;
        for (ll j = 0; j < n/2; j++)
        {
            pair<ll, ll> x;
            x.first = p[2*j+impares];
            x.second = (2*j+impares);
            max.push_back(x);
        }
        max.sort();
        for (ll j = 0; j < n/2; j++)
        {
            pair<ll, ll> x = max.front();
            q[x.second] = n-j-1;
            max.pop_front();
        }

        // Nas demais posições adiciona os maiores valores (q) nas posicoes com os menores valores(p)
        list<pair<ll, ll> > min;
        for (ll j = 0; j < n/2; j++)
        {
            pair<ll, ll> x;
            x.first = p[2*j-(impares-1)];
            x.second = (2*j-(impares-1));
            min.push_back(x);
        }
        min.sort();
        for (ll j = 0; j < n/2; j++)
        {
            pair<ll, ll> x = min.front();
            q[x.second] = n/2-j-1;
            min.pop_front();
        }

        for (ll j = 0; j < n; j++)
        {
            cout << q[j] + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}


/*
  .   .   .   . 
1 2 4 5 7 6 8 3      p
  8   6   5   7
4 8 3 6 2 5 1 7      q

5 10 7 11 9 11 9 10  a

*/