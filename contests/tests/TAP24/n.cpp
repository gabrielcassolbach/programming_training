#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<ll> values;
    values.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> values[i];
    }

    sort(values.begin(), values.end());
    
    ll result = 0;
    ll a, b, c;
    a = values[values.size()-1];
    b = values[0];
    c = values[0];

    result = (a-b)*(a-b)+(a-c)*(a-c)+(b-c)*(b-c);
    result /= 2;

    cout << result << "\n";

    return 0;
}
