#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
    int n;
    cin >> n;
    vector<int> v;
    v.resize(2*n + 2);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    for(int i = 0; i < n; i++)
        v[n+i] = v[i];
    ll ans = numeric_limits<ll>::min();
    for (int s = 0; s < n; s++) {
        ll sum = 0;
        for (int i = s; i < s + n - n%2; i += 2) {
            sum += v[i];
            if (sum > ans) {
                ans = sum;
            }
        }
    }

    cout << ans << endl;

}