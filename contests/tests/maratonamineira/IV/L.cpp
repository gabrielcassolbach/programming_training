#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    double n, m; cin >> n >> m;

    double total, part_m; cin >> total >> part_m;
    double ans = total - (part_m*m);

    cout << fixed << setprecision(2);
    cout << ans/(n-m) << '\n';
    return 0;
}
