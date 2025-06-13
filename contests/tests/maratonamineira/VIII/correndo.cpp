#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    double a, b;
    cin >> a >> b;
    cout << ceil(PI/acos(b/a)) << '\n';
    return 0;
}
