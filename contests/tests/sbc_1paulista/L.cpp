#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n; cin >> n; 
    if(n != 2) {
        cout << "S\n";
        return 0;
    }
    
    int p1; cin >> p1; 
    vector<int> v1(p1);
    for(int i = 0; i < p1; i++) cin >> v1[i];

    int p2; cin >> p2;
    vector<int> v2(p2); 
    for(int i = 0; i < p2; i++) cin >> v2[i];

    reverse(v2.begin(), v2.end());
    v1.insert(v1.end(), v2.begin(), v2.end());

    auto is_1 = [](int a) { return a == 1; };
    cout << (is_partitioned(v1.begin(), v1.end(), is_1) ? 'S' : 'N') << '\n';

    return 0;
}