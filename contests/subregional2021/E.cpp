#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;

queue<ll> q0, q1;

int main() { _

    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        ll t, d;
        cin >> t >> d;
        if(d){
            q1.push(t);
        } else {
            q0.push(t);
        }
    }

    ll t = 0;
    ll ts = 0;
    ll dir = -1;
    //cout << t << " " << dir << " " << ts << endl;

    while (!q0.empty() || !q1.empty()) {
        t++;
        if (ts <= 0) {
            dir = -1;
        }
        if (dir != 1) {
            while (!q0.empty() && q0.front() <= t) {
                ts = 10;
                q0.pop();
                dir = 0;
            }
        }
        if (dir != 0) {
            while (!q1.empty() && q1.front() <= t) {
                ts = 10;
                q1.pop();
                dir = 1;
            }
        }
        ts--;
        // << t << " " << dir << " " << ts << endl;
        
    }
    cout << t + 10 << endl;

    return 0;
}