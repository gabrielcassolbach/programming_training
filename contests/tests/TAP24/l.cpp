#include <bits/stdc++.h>

using namespace std;

using ll = long long;
template<typename T> using arr = vector<T>;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    arr<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    arr<ll> sum_one(n+1), sum_pow_two(n+1), sum_odd(n+1);
    sum_one[0] = sum_pow_two[0] = sum_odd[0] = 0;
    for(int i = 1; i <= n; ++i) {
        sum_one[i] = sum_one[i-1];
        sum_pow_two[i] = sum_pow_two[i-1];
        sum_odd[i] = sum_odd[i-1];
        if(a[i-1] == 1) {
            sum_one[i] += a[i-1];
        } else if((a[i-1] & -a[i-1]) == a[i-1]) {
            sum_pow_two[i] += a[i-1];
        } else if(a[i-1] & 1) {
            sum_odd[i] += a[i-1];
        }
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        ll sum_a = (sum_one[r]-sum_one[l-1]+1)/2+sum_pow_two[r]-sum_pow_two[l-1];
        ll sum_b = (sum_one[r]-sum_one[l-1])/2+sum_odd[r]-sum_odd[l-1];
        cout << (sum_a > sum_b ? 'A' : (sum_a < sum_b ? 'B' : 'E')) << '\n';
    }
    return 0;
}
