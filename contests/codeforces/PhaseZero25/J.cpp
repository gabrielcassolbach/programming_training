#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

int n, k; 
vector<int> v; 
// map. 

void read() {
    cin >> n >> k;  
    v.resize(n + 1);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    v[n+1] = -1;
}

int main() {
    fastio;
    read();
    for(int i = 0; i < n; i++){
        int j = (i + 1);
        while (v[i] + k * (j-i) <= v[j%n]) {
            j++;
        }
        cout << (j%n + 1) << " ";
    }
    cout << '\n';
    return 0; 
}