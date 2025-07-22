#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int k;
    cin >> k;
    vector<int> div;
    for(int d = 2; d*d <= k; ++d)
        if(k%d == 0) div.push_back(d);
    if((int)div.size() != 1 || div[0]*div[0] != k) {
        cout << "N\n";
    } else {
        bool is_prime = true;
        for(int d = 2; d*d <= div[0] && is_prime; ++d)
            if(div[0]%d == 0) is_prime = false;
        cout << (is_prime ? "S\n" : "N\n");
    }
    return 0;
}
