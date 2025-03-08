#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() { _
    int n, k; cin >> n; cin >> k;
    cout << (k - (n-1))/n << '\n';
    return 0;
}